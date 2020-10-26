// https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
using namespace std;


struct Tag {
    string id;
    map<string, string> attributes;
    map<string, Tag*> children;

    Tag() {}
    Tag(const string& line) {
         stringstream iss(line);
         iss >> id;
        string equal,tagname,value;
        while (iss >> tagname) {
            iss >> equal >> value;
            attributes.insert({tagname, value.substr(1, value.length()-2)});
       //     cout << id << " " << tagname <<  " " <<  equal << " " << value << endl;

        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int lines,queries;
    string line;
    map<string, Tag*> roots;
    stack<Tag*> st;


    cin >> lines;
    cin >> queries;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < lines; ++i) {
        getline(cin, line);

         if (line[1] != '/') {
             Tag* tagX = new Tag(line.substr(1, line.length()-2));
        //     cout << "ID: " << tagX->id  << endl;
            if (!st.empty()) 
                st.top()->children.insert({tagX->id,tagX});
            else 
                roots.insert({tagX->id,tagX});   
        
             st.push(tagX);

         }
         else {
            st.pop();
         }
    }


    for (int i = 0; getline(cin, line) && i < queries; ++i) {
        auto pos = line.find('~');
        istringstream tagss(line.substr(0, pos));

        string id;
        Tag* last=nullptr;
        bool found = true;
        while (getline(tagss, id, '.')) {
       //     cout << "query:" << id << endl;

       // either ways work. Search whether in the roots or under children.
       //     auto& mp = (last ? last->children : roots);
       //     auto it = mp.find(id);
            auto it = (last ? last->children.find(id) : roots.find(id));
            if (it == roots.end() || it == last->children.end()) {
                cout << "Not Found!" << endl;
                found = false;
                break;
            }
            last = (Tag *)it->second;
        }

        string attribute;
        if (found && last != nullptr) {
            istringstream attrss(line.substr(pos + 1));
            getline(attrss, attribute);
      //      cout << "attribute: " << attribute << endl;
            auto it = last->attributes.find(attribute);
            if (it != last->attributes.end())
                cout << it->second << endl;
            else
                cout << "Not Found!" << endl;
        }
    }
    return 0;
}

// https://www.hackerrank.com/challenges/messages-order/problem
// https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
// use operator < instead of defining the sorting predicate method

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
private:
    int seqID;
    string message;

public: 
    Message(int seqID,string message) {
        this->seqID = seqID;
        this->message = message;
    }
    const string& get_text() {
        return message;
    }

    bool operator < (const Message& msg) {
        if (this->seqID < msg.seqID)
            return true;
        
        return false;

    }
};

class MessageFactory {
private:
    int seqID;
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message msg = Message(++seqID,text);
        return msg;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}


/* reference

include <vector>
#include <algorithm>

using namespace std;

vector< MyStruct > values;

sort( values.begin( ), values.end( ), [ ]( const auto& lhs, const auto& rhs )
{
   return lhs.key < rhs.key;
});
*/

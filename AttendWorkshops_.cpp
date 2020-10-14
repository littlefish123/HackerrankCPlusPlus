#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start;
    int duration;
    int end;
};

struct Available_Workshops {
    int n;
    vector<Workshop> v;

    Available_Workshops(int& n) {
        this->n = n;
        v = vector<Workshop>(n);
    }
};

bool compare(Workshop& w1, Workshop& w2) {
    return w1.end < w2.end;
}


Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops* availWorkshop = new Available_Workshops(n);

    for (int i=0; i < n; i++) {
        availWorkshop->v[i].start = start_time[i];
        availWorkshop->v[i].duration = duration[i];
        availWorkshop->v[i].end = start_time[i] + duration[i];

    }
    sort(availWorkshop->v.begin(), availWorkshop->v.end(), compare);

    return availWorkshop;
}


int CalculateMaxWorkshops(Available_Workshops* ptr)  {
    int count=0,end=0;
    for (int i=0; i < ptr->n; i++) {
        if (ptr->v[i].start >= end) {
            count++;
            end = ptr->v[i].end;
        }
    }

    return count;

}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

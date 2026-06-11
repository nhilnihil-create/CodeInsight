#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

//        894510
#define N 100000
#define MAX 1000000000

int main() {

    int cnt = 0;
    long long q = 1;
    while(cnt++ < 10) {
        string ans;
        stringstream ss;
        ss << "? " << q;
        cout << ss.str() << endl;
        cin >> ans;

        if(ans == "Y") {
            q *= 10;
        } else {
            goto next;
        }
    }
    next:;
    if(cnt == 11) {
        string ans = "N";
        q = 1;
        for(; ans == "N"; q *= 10) {
            cout << "? " << 2 * q << endl;
            cin >> ans;
        }

        cout << "! " << q / 10 << endl;
        exit(0);
    }

    string answer = "";
    for(int i = 0; i < to_string(q - 1).size(); i++) {
        int l = 0, r = 9;
        vector< int > used(10, 0);
        while(l < r) {
            string ans;
            stringstream ss;

            int mid = (l + r) / 2.0;
            if(used[mid]++) mid++;
            string temp;
            if(i == to_string(q - 1).size() - 1) {
                temp = answer + to_string(mid);
                temp += "0";
            } else {
                temp = answer + to_string(mid);
            }
            ss << "? " << temp;
            cout << ss.str() << endl;
            cin >> ans;

            if(ans == "Y") {
                if(i == to_string(q - 1).size() - 1) r = mid;
                else l = mid;
            } else {
                if(i == to_string(q - 1).size() - 1) l = mid + 1;
                else r = mid - 1;
            }
        }
        answer += to_string(l);
    }
    cout << "! " + answer << endl;
    exit(0);
}

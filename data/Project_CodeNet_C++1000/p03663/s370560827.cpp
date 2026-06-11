#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
char ans;

int main() {
    //couto.precision(10);
    vector<int> digit(9);
    for(int i = 0; i < 9; i++) {
        int ok = -1;
        int ng = 9;
        if(i == 0) ok = 0;
        while(ng - ok > 1) {
            int mid = (ok + ng) / 2;
            cout << "? ";
            for(int j = 0; j < i; j++) cout << digit[j];
            cout << mid;
            for(int j = 0; j < 9; j++) cout << "9";
            cout << endl;
            cin >> ans;
            if(ans == 'Y') ng = mid;
            else ok = mid;
        }
        digit[i] = ok + 1;
    }
    digit.push_back(0);
    while(digit.back() == 0) {
        vector<int> sub;
        for(int i = 0; i < digit.size(); i++) sub.push_back(digit[i]);
        ll a = 0;
        ll b = 0;
        for(int i = 0; i < sub.size(); i++) {
            a *= 10;
            a += sub[i];
        }
        for(int i = 0; i + 1 < sub.size(); i++) {
            b *= 10;
            b += sub[i];
        }
        ll query = (a + b) / 2;
        cout << "? " << query << endl;
        cin >> ans;
        if((ans == 'N') ^ (to_string(query) <= to_string(b))) break;
        digit.pop_back();
    }
    cout << "! ";
    for(int i = 0; i < digit.size(); i++) cout << digit[i];
    cout << endl;
    return 0;
}

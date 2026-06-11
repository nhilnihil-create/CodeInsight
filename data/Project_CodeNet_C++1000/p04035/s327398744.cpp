#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1e9;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,L;
    cin >> N >> L;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    bool ret = false;
    int a = 0;
    for(int i = 0;i < N - 1;i++) {
        if(vec.at(i) + vec.at(i + 1) >= L) {
            ret = true;
            a = i + 1;
            break;
        }
    }
    if(ret == false) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        vector<int> ret2;
        ret2.push_back(a);
        for(int i = a - 1;i >= 1;i--) {
            ret2.push_back(i);
        }
        for(int i = a + 1;i <= N - 1;i++) {
            ret2.push_back(i);
        }
        reverse(ret2.begin(),ret2.end());
        for(int i = 0;i < N - 1;i++) {
            cout << ret2.at(i) << endl;
        }
    }
}
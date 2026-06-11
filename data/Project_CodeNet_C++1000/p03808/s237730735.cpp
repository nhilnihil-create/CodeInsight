#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    ll cnt = 0;
    for(int i = 0;i < N;i++) {
        cnt += vec.at(i);
    }
    ll cnt2 = (1 + N) * N / 2;
    if(cnt % cnt2 != 0) {
        cout << "NO" << endl;
    }
    else {
        vec.push_back(vec.at(0));
        cnt /= cnt2;
        ll cnt3 = 0;
        bool ret = true;
        for(int i = 0;i < N;i++) {
            if(((vec.at(i + 1) - vec.at(i)) - cnt) % N != 0 || vec.at(i + 1) - vec.at(i) - cnt > 0) {
                ret = false;
            }
            else {
                cnt3 += ((vec.at(i + 1) - vec.at(i)) - cnt) / -N;
            }
        }
        if(ret == false) {
            cout << "NO" << endl;
        }
        else {
            if(cnt3 == cnt) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
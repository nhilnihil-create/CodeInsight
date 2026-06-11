#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++) {
        cin >> A.at(i);
    }
    vector<int> B(N);
    for(int i = 0;i < N;i++) {
        cin >> B.at(i);
    }
    vector<P> cnt(N);
    cnt.at(0).first = A.at(0);
    cnt.at(0).second = A.at(0);
    for(int i = 0;i < N - 1;i++) {
        if(A.at(i) == A.at(i + 1)) {
            cnt.at(i + 1).first = 1;
            cnt.at(i + 1).second = cnt.at(i).second;
        }
        else {
            cnt.at(i + 1).first = A.at(i + 1);
            cnt.at(i + 1).second = A.at(i + 1);
        }
    }
    vector<P> cnt2(N);
    reverse(B.begin(),B.end());
    cnt2.at(0).first = B.at(0);
    cnt2.at(0).second = B.at(0);
    for(int i = 0;i < N - 1;i++) {
        if(B.at(i) == B.at(i + 1)) {
            cnt2.at(i + 1).first = 1;
            cnt2.at(i + 1).second = cnt2.at(i).second;
        }
        else {
            cnt2.at(i + 1).first = B.at(i + 1);
            cnt2.at(i + 1).second = B.at(i + 1);
        }
    }
    reverse(cnt2.begin(),cnt2.end());
    vector<P> ret(N);
    bool ret2 = true;
    for(int i = 0;i < N;i++) {
        ret.at(i).first = max(cnt.at(i).first,cnt2.at(i).first);
        ret.at(i).second = min(cnt.at(i).second,cnt2.at(i).second);
        if(ret.at(i).first > ret.at(i).second) {
            ret2 = false;
            break;
        }
    }
    if(ret2 == false) {
        cout << 0 << endl;
    }
    else {
        ll ret3 = 1;
        for(int i = 0;i < N;i++) {
            ret3 = ret3 * (ret.at(i).second - ret.at(i).first + 1) % MOD;
        }
        cout << ret3 << endl;
    }
}
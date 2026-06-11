//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    map<ll,int> mp;
    vecl A(N);
    REP(i,N) {
        ll a; cin >> a;
        if(mp.count(a)) mp[a]++;
        else mp[a] = 1;
        A[i] = a;
    }
    sort(A.begin(),A.end(),greater<ll>());
    ll ans;
    ll h = 0;
    ll w = 0;
    REP(i,A.size()) {
        if(mp[A[i]] < 2) continue;
        else if(mp[A[i]] >= 4) {
            h = w = A[i];
            cout << h*w << endl;
            return 0;
        } else {
            h = A[i];
            break;
        }
    }

    REP(i,A.size()) {
        if(mp[A[i]] < 2 || A[i] == h) continue;
        else {
            w = A[i];
            break;
        }
    }

    cout << h*w << endl;
}

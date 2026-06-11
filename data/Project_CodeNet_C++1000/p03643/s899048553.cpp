#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) (int i=a;i<n;i++)
#define per(i,a,n,s) (int i=n-1;i>=a;i--)
#define range(...) _overload3(__VA_ARGS__,per,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define vecin(x) for(auto&youso_: (x) ) cin >>  youso_
#define vecout(x) for(auto&youso_: (x) ) cout << youso_ << " " ; cout << endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int inf = 1e9+10;
const int mod = 1e9+7;
const long long llinf = 1e18;
#define _GLIBCXX_DEBUG
// head

int main(){
    int n;
    cin >>n;
    cout << "ABC" << n << endl;
}
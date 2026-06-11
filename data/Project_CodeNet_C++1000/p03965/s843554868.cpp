#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    string s;cin >> s;
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++) if(s[i]=='p') cnt++;
    int num=n/2;
    num-=cnt;
    cout << num << endl;
    return 0;
}
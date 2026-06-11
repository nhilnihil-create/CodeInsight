#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
 
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
using namespace std;
 
void solve(){
	char s[15];
    string t="";
    scanf("%s",s);
    rep(i,4)t+=string{s[i]};
    t+=" ";
    for(int j=4;j<12;++j)t+=string{s[j]};
    cout<<t<<"\n";
}
 
 
signed main(){
	ios::sync_with_stdio(false);
        cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
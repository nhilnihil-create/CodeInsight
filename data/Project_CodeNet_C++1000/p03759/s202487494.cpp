#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<28;
const long long MOD =1000000000+7;
void solve(int a){cout<<( a?"YES":"NO")<<endl;}
int main(){
	int a,b,c;
	cin >>a>>b>>c;
	solve(b-a==c-b);
}
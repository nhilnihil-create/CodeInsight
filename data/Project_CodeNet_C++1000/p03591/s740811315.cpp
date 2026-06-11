#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<28;

void solve(int a){cout<<( a?"Yes":"No")<<endl;}
int main(){
	string n;
	cin >>n;
	bool ans=false;
	string F="YAKI";
	solve(equal(F.begin(),F.end(),n.begin()));
}
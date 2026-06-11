#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	string s,t; cin>>s>>t;
	int n=s.size(),m=t.size();
	if(n>m){
		cout<<"GREATER"<<endl;
		return 0;
	}
	else if(n<m){
		cout<<"LESS"<<endl;
		return 0;
	}
	int type=3;
	rep(i,0,n){
		string a,b;
		a.push_back(s[i]);
		b.push_back(t[i]);
		int c=stoi(a);
		int d=stoi(b);
		if(c>d){
			type=1;
			break;
		}
		else if(c<d){
			type=2;
			break;
		}
	}
	if(type==1) cout<<"GREATER"<<endl;
	else if(type==2) cout<<"LESS"<<endl;
	else cout<<"EQUAL"<<endl;
	
	return 0;
}
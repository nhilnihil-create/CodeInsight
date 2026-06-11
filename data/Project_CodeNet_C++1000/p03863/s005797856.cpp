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
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fi first
#define se second
using ll=long long int;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

int main(){
	string s;
	cin>>s;
	char key=s[0],key2=s[1];
	bool judge=true;
	for(int i=0;i<s.size();i+=2){
		if(s[i]!=key)judge=false;
	}
	if(judge){
		for(int i=1;i<s.size();i+=2){
			if(s[i]!=key2)judge=false;
		}
	}
	int cnt=0;
	if(!judge)cnt=s.size()-2-(s[0]==s[s.size()-1]);
	else cnt=0;
	if(cnt%2==0)cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}

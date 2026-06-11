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
	if((s.size()-2-(s[0]==s[s.size()-1]))%2==0)cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}

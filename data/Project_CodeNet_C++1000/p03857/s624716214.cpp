#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*

*/

int main(void){
	ll n,k,l,t1[200010]={},t2[200010]={};
	vector<ll> v1[200010],v2[200010];
	map<mp,ll> M;
	cin>>n>>k>>l;
	rep(i,k){
		ll p,q;
		cin>>p>>q;
		v1[p].push_back(q);
		v1[q].push_back(p);
	}
	rep(i,l){
		ll p,q;
		cin>>p>>q;
		v2[p].push_back(q);
		v2[q].push_back(p);
	}
	reg(i,1,n){
		if(t1[i]==0){
			t1[i]=i;
			queue<ll> Q;
			Q.push(i);
			while(!Q.empty()){
				ll p=Q.front();Q.pop();
				rep(j,v1[p].size()){
					ll q=v1[p][j];
					if(t1[q]==0){
						t1[q]=i;
						Q.push(q);
					}
				}
			}
		}
	}
	reg(i,1,n){
		if(t2[i]==0){
			t2[i]=i;
			queue<ll> Q;
			Q.push(i);
			while(!Q.empty()){
				ll p=Q.front();Q.pop();
				rep(j,v2[p].size()){
					ll q=v2[p][j];
					if(t2[q]==0){
						t2[q]=i;
						Q.push(q);
					}
				}
			}
		}
	}
	reg(i,1,n){
		M[make_pair(t1[i],t2[i])]++;
	}
	reg(i,1,n){
		printf("%lld ",M[make_pair(t1[i],t2[i])]);
	}
	return 0;
}
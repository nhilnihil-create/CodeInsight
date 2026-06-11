#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
ll a[114514],b[114514],c[114514],d[114514];
ll cntA[114514],cntB[114514];
ll cnTA[114514],cnTB[114514];
signed main(){
	ll q;
	string s,t;
	cin>>s>>t>>q;
	rep(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];
	ll n=s.size(),m=t.size();
	rep(i,n){
		if(s[i]=='A'){
			cntA[i+1]=cntA[i]+1;
			cntB[i+1]=cntB[i];
		}
		else {
			cntA[i+1]=cntA[i];
			cntB[i+1]=cntB[i]+1;
		}
	}
	rep(i,m){
		if(t[i]=='A'){
			cnTA[i+1]=cnTA[i]+1;
			cnTB[i+1]=cnTB[i];
		}
		else {
			cnTA[i+1]=cnTA[i];
			cnTB[i+1]=cnTB[i]+1;
		}
	}
	rep(i,q){
		ll aa=cntA[b[i]]-cntA[a[i]-1];
		ll bb=cntB[b[i]]-cntB[a[i]-1];
		ll cc=cnTA[d[i]]-cnTA[c[i]-1];
		ll dd=cnTB[d[i]]-cnTB[c[i]-1];
		ll memoa=cc-aa,memob=dd-bb;
		if(abs(memoa-memob)%3==0)puts("YES");
		else puts("NO");
	}
}
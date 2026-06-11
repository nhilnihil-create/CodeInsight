#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int N=1e5+3;
int n,a,b;
ll h[N];
bool check(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(h[i]<=x*b) continue;
		sum+=(h[i]-x*b)/(a-b);
		if((h[i]-x*b)%(a-b)) sum++;
	}
	if(sum<=x) return true;
	return false;
}
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>h[i];
    int l=1,r=1e9;
	while(r-l>5){
		int m=(l+r)>>1;
		if(check(m)) r=m;
		else l=m;
	}
	while(l<=r){
		if(check(l)) break;
		l++;
	}
	cout<<l<<endl;
    return 0;
}
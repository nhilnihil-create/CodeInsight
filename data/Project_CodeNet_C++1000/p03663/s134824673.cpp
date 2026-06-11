#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
ll qry(ll x)
{
	cout<<"? "<<x<<endl;
	string g; cin>>g;
	return g[0]=='Y';
}
int main()
{
	int s=qry(1e9);
	if(s)
		for(int i=2;;i*=10)
			if(qry(i))
			{
				cout<<"! "<<i/2<<endl;
				return 0;
			}
	ll p;
	for(ll g=0,s=1;;s*=10,++g)
		if(!qry(s)) {p=s/10; break;}
	ll l=p,r=p*10-1;
	while(l<r)
	{
		ll m=(l+r)>>1;
		if(!qry(m*10)) l=m+1; else r=m;
	}
	cout<<"! "<<l<<endl;
}

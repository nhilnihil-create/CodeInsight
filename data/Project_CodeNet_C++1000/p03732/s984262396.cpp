//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han Elmuzaffer Daima
//Bismillahirrahmanirrahim

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long int lo;
typedef pair< int,int > PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(lo i=1;i<=n;i++)
#define mid (start+end)/2
#define ort (bas+son)/2

const lo MAX = -1000000000000000000; 
const lo MIN = 1000000000000000000; 
const lo inf = 1000000000; 
const lo KOK = 100000; 
const lo LOG = 30; 
const lo li = 2000005; 
const lo mod = 1000000007; 

lo n,m,cev,b,a[li],k,v[li],w[li],at,dp[105][105][305];
string s;
//~ vector<lo> v;

inline lo f(lo sira,lo kac,lo W){
	//~ cout<<at<<endl;
	lo cevv=-inf;
	if(sira>n){
		if(kac*at+W<=m) return 0;
		return -inf;
	}
	if(~dp[sira][kac][W]) return dp[sira][kac][W];
	cevv=max(cevv,f(sira+1,kac+1,W+w[sira])+v[sira]);
	cevv=max(cevv,f(sira+1,kac,W));
	return dp[sira][kac][W]=cevv;
}

inline lo solve(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&n,&m);
	FOR{
		scanf("%lld %lld",&w[i],&v[i]);
		if(i>1)
			w[i]=w[i]-w[1];
		//~ cout<<w[i]<<endl;
	}
	at=w[1];
	//~ cout<<at<<endl;
	w[1]=0;
	printf("%lld\n",f(1,0,0));
	return 0;
}

int main(void){
	solve();
	
	return 0;
}

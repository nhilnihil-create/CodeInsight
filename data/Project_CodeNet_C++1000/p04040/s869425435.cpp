#include <bits/stdc++.h>
  using namespace std;
#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define set0(k,n) for(int nn=0;nn<(n);nn++){ (k).push_back(0); }
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define vecsize(b,size) vector<int> (b)((size));
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsl(s) vector<pair<ll,ll>> (s);
#define pairss(s) vector<pair<string,string>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairspl(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsps(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsREV(s) (s).push_back(make_pair(bb,aa));
#define pairslREV(s) (s).push_back(make_pair(bb,aa));
#define pairssREV(s) (s).push_back(make_pair(bb,aa));
#define MOD 1000000007


ll inv(ll a){
	
	ll res=1;
	int p=MOD-2;
	while(p>0){
		if(p&1==1){res*=a;res%=MOD;}
		a=a*a%MOD;
		p>>=1;
	}
	return res;
}

int main() {
	
	int H,W,A,B;
	cin>>H>>W>>A>>B;
	ll fact[310000];
	ll invfact[320000];
	
	fact[0]=1;
	fx(H+W+5){
		fact[x+1]=fact[x]*(x+1);
		fact[x+1]%=MOD;
	}
	invfact[H+W+4]=inv(fact[H+W+4]);
	for(int x=H+W+3;x>=0;x--){
		invfact[x]=invfact[x+1]*(x+1);
		invfact[x]%=MOD;
	}
	
	ll ans=0;
	
	for(int x=1;x<=H-A;x++){
		ll sum=fact[B+x-2]*invfact[x-1];
		sum%=MOD;
		sum=(sum*invfact[B-1])%MOD;
		ll sum2=fact[W-B-1+H-x]*invfact[W-B-1];
		sum2%=MOD;
		sum2=(sum2*invfact[H-x])%MOD;
		ans+=(sum*sum2)%MOD;
      ans%=MOD;

	}
	ce(ans)
	
	
}
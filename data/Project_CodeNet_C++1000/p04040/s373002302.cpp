#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int mod=1e9+7;
const int MAX=3e5+5;
int fact[MAX];
int ans=0;
int fastpow(int a,int b)
{
	int wynik=1;
	while (b)
	{
		if (b&1)wynik=((ll)wynik*a)%mod;
		a=((ll)a*a)%mod;
		b>>=1;
	}
	return wynik;
}

int binom(int a,int b)
{
	int licznik=fact[a];
	int mianownik=((ll)fact[b]*fact[a-b])%mod;
	//cout<<"TERAZ "<<licznik<<" "<<mianownik<<"\n";
	return ((ll)licznik*fastpow(mianownik,mod-2))%mod;
}

int ways(int x1,int y1,int x2,int y2)
{
	return binom(x2-x1+y2-y1,x2-x1);
}
int32_t main()
{
  BOOST;
  fact[0]=1;
  for (int i=1;i<MAX;i++)fact[i]=((ll)fact[i-1]*i)%mod;
  int n,m,a,b;
  cin>>n>>m>>a>>b;
  ll prefiks=0;
  int licznik=0;
  for (int i=n-a;i>=1;i--)
  {
    int x=i,y=b+1+licznik;
    if (y>m)break;
    ans=((ll)ans+(ll)ways(1,1,x,y)*ways(x,y,n,m))%mod;
    licznik++;
  }
  cout<<ans;
  return 0;
}

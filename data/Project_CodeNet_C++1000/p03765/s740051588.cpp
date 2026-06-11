#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
const int N=2e5+5;
	
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1,s2;
	cin>>s1>>s2;
	ll t;
	cin>>t;
	
	ll ca[100050]={0};
	ll cb[100050]={0};
	
	ll Ca[100050]={0};
	ll Cb[100050]={0};
	
	ll n=max(s1.length(),s2.length());
	
	ll i;
	for(i=0;i<s1.length();i++)
	{
		ca[i+1]=ca[i];
		cb[i+1]=cb[i];
		
		if(s1[i]=='A')
			ca[i+1]++;
		else
			cb[i+1]++;
	}
	for(;i<n;i++)
	{
		ca[i+1]=ca[i];
		cb[i+1]=cb[i];
	}
	for(ll i=0;i<s2.length();i++)
	{
		Ca[i+1]=Ca[i];
		Cb[i+1]=Cb[i];
		
		if(s2[i]=='A')
			Ca[i+1]++;
		else
			Cb[i+1]++;
	}
	for(;i<n;i++)
	{
		Ca[i+1]=Ca[i];
		Cb[i+1]=Cb[i];
	}
	
	for(ll i=0;i<t;i++)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		
		ll cnta= ca[b]-ca[a-1];
		ll cntb= cb[b]-cb[a-1];
		
		ll c1=cnta + 2*cntb;
		
		ll Cnta= Ca[d]-Ca[c-1];
		ll Cntb= Cb[d]-Cb[c-1];
		ll c2=Cnta + 2*Cntb;
		//cout<<cnta<<" "<<cntb<<" "<<Cnta<<" "<<Cntb<<endl;
		
		while(c1<c2)
		{
			c1*=4;
		}
		if((c1-c2)%3==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
		
	}
}
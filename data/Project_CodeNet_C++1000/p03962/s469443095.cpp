#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp> 
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> pseudo_set;
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define chotu ((int)1e9+7)
//sieve generation begin
vi PRIME;
void sieve(int n)
{
	bool a[n+1];
	memset(a,0,sizeof(a));
	a[0]=1;
	a[1]=1;
	for(int i=2;i*i<=n;i++)
	{
		if(a[i]==0)
		{
			for(int j=i*i;j<=n;j+=i)
			a[j]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]==0)
		PRIME.pb(i);
	}
}
//sieve generation end
ll gcd(ll a,ll b)
{
	while(b%a)
	{
		ll c=b;
		b=a;
		a=c%a;
	}
	return a;
}
ll bigpow(ll x,ll y)
{
	if(y==0)
	return 1;
	else if(y&1)
	{
		return (x*bigpow((x*x)%chotu,(y-1)/2))%chotu;
	}
	else 
	return bigpow((x*x)%chotu,y/2);
}
//fastio
/*void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c=='-') 
    { 
        
        negative = true; 
  
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 
*/
void solve()
{
si s;
for(int i=0;i<3;i++)
{
	int x;
	cin>>x;
	s.insert(x);
}
cout<<s.size();
}
int main()
{
//code
fastio
int t;
t=1;
while(t--)
{
	solve();
	cout<<'\n';
}
}
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
using namespace std;

 ll mod=1e9 +7;

ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
 
vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

ll get_val(vector<ll>&ft,ll index)
{
  ll res=0;
  for(;index>=0;index=(index & (index+1))-1)
    res+=ft[index];
  return res;
}

void update(vector<ll>&ft,ll index,ll val)
{
  for(;index<(ll)ft.size();index|=index+1)
    ft[index]+=val;
}

ll bs(ll num,ll a,ll b,ll tot)
{
  ll lo=0,hi=num/a +1;
  ll res=-1;
  while(hi>=lo)
  {
    ll mid=(lo+hi)/2;
    if(mid*a + (tot-mid)*b >=num)
    {
      res=mid;
      hi=mid-1;
    }
    else lo=mid+1;
  }
  return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //   #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // Sieve();
   ll tests=1;
 // cin>>tests;
  // ll t=1;
    while(tests--)
    {
      ll n,a,b,i,j,ans=0;
      cin>>n>>a>>b;
      vector<ll>h(n);
      rep(i,0,n-1) cin>>h[i];
      sort(all(h));
      // reverse(all(h));
      ll hi=1000000000,low=0;
      while(hi>=low )
      {
        ll mid=(low+hi)/2;
        ll cur=0;
        bool flag=true;
        for(i=0;i<n;i++)
        {
          if(h[i]<=mid*b) continue;
          else
          {
            ll tmp=bs(h[i],a,b,mid);
            if(tmp==-1) {flag=false;break;}
            else cur+=tmp;
          }
        }
        if(!flag) {low=mid+1;continue;}
        // cout<<"cur- "<<cur<<" "<<"mid "<<mid<<"\n";
        if(cur<=mid) {ans=mid;hi=mid-1;}
        else low=mid+1;
      }
      // cout<<bs(20,10,4,4)<<"\n";
      cout<<ans;

    }

    return 0;
   }
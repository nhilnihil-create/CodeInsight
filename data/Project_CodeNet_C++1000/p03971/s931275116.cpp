#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define N 100005
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795

ll no_of_div(ll a)
{
  ll cnt=0,i;
  if (a==2)return 1;
  for(i=2;i*i<a;i++)
  {
if(a%i==0)cnt+=2;
  }
  if(i*i==a)cnt++;
  return cnt;
}

//vl a(1001);

ll powM(ll a,ll b, ll m)
{ 
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans%m;
}

ll abc(ll x)
{
  ll cnt_f=0,cnt_s=0;
  while(x)
  {
    ll dig=x%10;
    if(dig==4)cnt_f++;
    else cnt_s++;
    x/=10;
  }
  return (cnt_f==cnt_s);
}

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll n,a,b;
cin>>n>>a>>b;
string s;cin>>s;
s.insert(s.begin(),'d');

ll cnt_a=0,cnt_b=0,bb=1;

for(int i=1;i<s.size();i++)
{
  if(s[i]=='c')cout<<"No"<<"\n";
  else if(s[i]=='a')
  {
    if(cnt_a+cnt_b<a+b)
      {
        cout<<"Yes"<<"\n";
        cnt_a++;
      }
    else cout<<"No"<<"\n";
    //cnt_a++;
  }
  else 
    {
      if((cnt_a+cnt_b<a+b)&&(bb<=b))
        {
          cout<<"Yes"<<"\n";
          cnt_b++;
        }
      else cout<<"No"<<"\n";
        bb++;
    }
}

  return 0;



}


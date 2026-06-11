#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define F(i,a,b) for(i=a;a<=b;i++)
#define arr(a,n) for( i=0;i<n;i++)cin>>a[i];
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define vi vector<ll>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define s() sort(a,a+n);
#define sr() sort(a,a+n,greater<ll>());
#define v()  sort(v.begin(),v.end());
#define vr() sort(v.begin(),v.end(),greater<ll>());
#define mod 1000000007
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
int main() {
   /* #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
        

fast();
//ll t;cin>>t;while(t--)
{
    string s,ss;
    cin>>s;
    ss=s;
    ll n=s.length(),ans=INT_MAX;
    //cout<<n<<endl;
    string t="";
    for(int i=0;i<26;i++)
{
      char c='a'+i;
      map<char,ll>m;
       s=ss;
      ll count=0;
      for(int k=0;k<s.length();k++)
      {
        m[(s[k])]++;
      }
      if(m.size()==1)
        {
           //cerr<<" first if"<<endl;
           ans=min(ans,count);
           break;
        }
        else
        {
          m.clear();
        }
    
    

      
      while(m.size()!=1)
    {
      //cout<<" S = "<<s<<" "<<c<<endl;
       for(int j=0;j<s.length()-1;j++)
      {
        if(s[j]==c||s[j+1]==c)
        {
          t=t+c;
          m[(c)]++;
        }
        else
        {
          t=t+s[j];
          m[(s[j])]++;
        }
        

      }
     //cout<<" S = "<<s<<" "<<s.length()<<" "<<c<<endl;
      //cerr<<"T = "<<t<<" "<<t.length()<<endl;
        
           count++;
        if(m.size()==1)
        {
          //cout<<"IF Second "<<count<<endl;
          ans=min(ans,count);
          m.clear();
        s=t;
        t="";
           break;
        }
        m.clear();
        s=t;
        t="";
    }
      
   
}
    cout<<ans<<endl;
}
return 0;
}
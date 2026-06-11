#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ld long double
#define f first
#define mt make_tuple
#define s second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define time_bata cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define vec std::vector<int > v;
#define eps 1e-7
#define endl "\n"
#define mp make_pair
#define p_q priority queue


#define dbg(x) cout<<"#x"<<" = "<<x<<endl
#define dbg2(x,y) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define dbg4(x,y,z,q) cout<<"#x"<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl


#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR_(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
     
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
    return a.f<b.f;
}


bool check(int a){
    int sum=0;
    while(a>0){
        sum+=(a%10);
        a/=10;
    }
    if(sum==10) return true;
    return false;
}
void solve()
{
   int n;
   cin>>n;
   string s[2];
   cin>>s[0]>>s[1];
   int row=0,i;
   for(i=0;i<n;i++)
   {
    if(s[row][i]>='3')
    {
        if(s[row^1][i]<'3')
        {
            break;
        }
        else
        {
            row=row^1;
        }
    }
   }
   if(row==1 && i==n)
   {
    cout<<"YES"<<endl;
   }
   else
   {
    cout<<"NO"<<endl;
   }
}
ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 

int main()
{
  



        
    fast;
    int t=1,x;
     // cin>>t;
   
    while(t--)
    {

        int n,x;
        cin>>n;
        vector< pair<int ,int > > v;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            v.push_back({x,i});
        }
        int pos=0,ans=0;
        sort(v.begin(),v.end(),cmp);
       for(auto it:v)
       {
        if(it.s%2!=pos%2)
        {
            ans++;
        }
        pos++;
       }
       cout<<ans/2<<endl;
    }
    
    time_bata;
    return 0; 
  
}
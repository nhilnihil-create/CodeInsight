#include<bits/stdc++.h>
using namespace std;
#define dscan(a,b) scanf("%d %d",&a,&b);
#define scan(a) scanf("%d",&a);
#define pin(a) printf("%d\n",a)
#define pll(a) printf("%I64d\n",a);
#define inf 1000000009
#define infmx 1e18
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define all(x) x.begin(),x.end()
typedef pair<int,int>pi;
typedef pair<long long,long long>pll;
typedef vector<int>vi;
const int N=2100000;
ll mod=1e9+7;
int power(int a,int p){int r=1,y=a;while(p){if(p&1)r=(1LL*r*y)%mod;p>>=1;y=(1LL*y*y)%mod;}return r;}
int ara[N];
int main()
{
    IOS;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        ara[a]++;
    }
    int res=0;
    for(int i=1;i<=100000;i++){
        int temp=ara[i]+ara[i-1]+ara[i+1];
        res=max(res,temp);
    }
    cout<<res<<endl;
}

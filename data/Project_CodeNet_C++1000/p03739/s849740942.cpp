#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define pi pair<int, int>
#define ps pair<string, string>
#define pl pair<long, long>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vl vector<long>
#define vi vector<int>
#define vs vector<string>
#define vps vector< ps >
#define vpi vector< pi >
#define vpl vector< pl >
#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc(t,T) for(long long t=0;t<T;t++)
#define rep(i,s,n,d) for(long long i=s;i<n;i=i+d)

bool sortbysec(const pll &a,
              const pll &b)
{
    return (a.second < b.second);
}

void func(void)
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
}
int main(){


    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n,1)cin>>a[i];
    ll sum1=a[0];
    ll count1=0;
    ll d=0;
    if(a[0]<=0){
        sum1=1;
        count1=count1+abs(a[0]-1);
    }
   rep(i,1,n,1){
       ll sum3=a[i]+sum1;
    if(sum3*sum1>=0){
        if(sum1>0)
        d=-1;
        else d=1;
        count1=count1+abs(sum3-d);
        sum1=d;
    }
    else sum1=sum1+a[i];
   }
   ll sum2=a[0];
   ll count2=0;
   d=0;
     if(a[0]>=0){
        sum2=-1;
        count2=count2+abs(a[0]+1);
    }

   rep(i,1,n,1){
    ll sum3=a[i]+sum2;
    if(sum3*sum2>=0){
        if(sum2>0)
        d=-1;
        else d=1;
        count2=count2+abs(sum3-d);
        sum2=d;
    }
    else sum2=sum2+a[i];
   }
   cout<<min(count1,count2)<<endl;


}

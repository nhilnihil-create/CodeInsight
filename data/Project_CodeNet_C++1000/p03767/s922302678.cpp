#include<bits/stdc++.h>

using namespace std;

#define LL           long long
#define ULL          long long unsigned
#define LD           long double
#define ff              first
#define ss              second
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(LL i=0;i<n;i++)
#define RFOR(i,n)    for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(LL i=n-1;i>=0;i--)
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(LL i=a;i<=b;i++)
#define fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a)       a.begin(),a.end()
#define ABS(x)       ((x)<0?-(x):(x))
#define NL           "\n"
#define pb           push_back
#define mk              make_pair
#define pi           acos(-1.0)
#define prec(n)      fixed << setprecision(n)
#define sq(a)          (a)*(a)
#define asi          cout<<"check"<<" ";
#define all_set(arr,val) memset(arr,val,sizeof(arr))

int main()
{
    fast;
    LL i,j,k,x,sum=0,n,kount=0;
    vector<LL>vec;
    cin>>n;
    FLR(i,3*n){
        cin>>x;
        vec.pb(x);
    }
    sort(all(vec));
    for(i=3*n-2;i>=0;i-=2){
        sum+=vec[i];
        kount++;
        //cout<<vec[i]<<NL;
        if(kount==n)break;
    }
    cout<<sum;
}

#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX];
int cost(int x,int y)
{
    return (x-y)*(x-y);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll ans=INT_MAX,n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=-10000; i<=10000;i++){
        ll cur=0;
        for(int j=0;j<n;j++){
            cur+=cost(arr[j],i);
        }
    ans=min(ans,cur);
    }
    cout<<ans<<endl;

    return 0;
}

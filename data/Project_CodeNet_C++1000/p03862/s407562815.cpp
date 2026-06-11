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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,x,cnt=0;
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(arr[i-1]+arr[i]>x)
        {
            int cur=arr[i-1]+arr[i];
            int red=cur-x;
            cnt+=red;
            if(arr[i]>=red)
                arr[i]-=red;
            else
            {
                red-=arr[i];
                arr[i]=0;
                arr[i-1]-=red;
            }

        }
    }
    cout<<cnt<<endl;

    return 0;
}

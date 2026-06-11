#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%10==0)
    {
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if((sum-arr[i])%10!=0){
                cout<<sum-arr[i]<<endl;
                return 0;
            }
        }
        cout<<0;
        return 0;
    }
    cout<<sum<<endl;


}


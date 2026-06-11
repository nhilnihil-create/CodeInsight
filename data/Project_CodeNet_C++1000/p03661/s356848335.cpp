#include <bits/stdc++.h>
using namespace std;



typedef long long ll;
int arr[200005];
ll psum[200005];

int main()
{
    int n;
    cin>>n;
    ll tot=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        tot+=arr[i];
    }


    for(int i=1;i<=n;i++)
        psum[i]=psum[i-1]+arr[i];

    ll ret=1e15;
    for(int i=1;i<n;i++)
        ret=min(ret,abs(tot-psum[i]-psum[i]));
    cout<<ret;

}

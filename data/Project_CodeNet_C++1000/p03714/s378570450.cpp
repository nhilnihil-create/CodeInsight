#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    ll n;
    cin>>n;
    ll arr[3*n];
    ll arr_rev[3*n];
    for(ll i=0;i<3*n;i++)
    {
        cin>>arr[i];
        arr_rev[3*n-i-1] = arr[i];
    }
    ll prefix_sum1[3*n];
    priority_queue <ll, vector<ll>, greater<ll>> top_n;
    
    prefix_sum1[0] = arr[0];
    top_n.push(arr[0]);
    for(ll i=1;i<n;i++)
    {
        prefix_sum1[i] = prefix_sum1[i-1] + arr[i];
        top_n.push(arr[i]);
    }
    
    for(ll i=n; i<3*n-n; i++)
    {
        if(arr[i] > top_n.top())
        {
          prefix_sum1[i] = prefix_sum1[i-1] - top_n.top() + arr[i];
            top_n.pop();
            top_n.push(arr[i]);
        }
        else
            prefix_sum1[i] = prefix_sum1[i-1];
    }
    
//    for(int i=n-1; i<3*n-n;i++)
//    {
//        cout<<prefix_sum1[i]<<"\t";
//    }
    
    ll prefix_sum2[3*n];
    priority_queue <ll> bottom_n;
    prefix_sum2[0] = arr_rev[0];
    bottom_n.push(arr_rev[0]);
    for(ll i=1;i<n;i++)
    {
        prefix_sum2[i] = prefix_sum2[i-1] + arr_rev[i];
        bottom_n.push(arr_rev[i]);
    }
    
    
    for(ll i=n; i<3*n-n; i++)
    {
        if(arr_rev[i] < bottom_n.top())
        {
            prefix_sum2[i] = prefix_sum2[i-1] - bottom_n.top() + arr_rev[i];
            bottom_n.pop();
            bottom_n.push(arr_rev[i]);
        }
        else
            prefix_sum2[i] = prefix_sum2[i-1];
    }
//    cout<<"\n";
    ll ans = -922337203685477580;
    for(int i=3*n-n-1,j=n-1; i>=n-1 && j<3*n-n; i--, j++)
    {
//        cout<<prefix_sum2[i]<<"\t";
        ans  = max(ans, prefix_sum1[i] - prefix_sum2[j]);
    }
    
    cout<<ans;
    
    return 0;
}
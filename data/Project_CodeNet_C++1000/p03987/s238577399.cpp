#include <iostream>
#include <stack>
using namespace std;
using ll=long long;
int main() {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<ll>s;
    ll left[n],right[n];

    for(ll i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>arr[i]){
            s.pop();
        }
        if(s.empty()){
            left[i]=i+1;
        }
        else{
            left[i]=i-s.top();
        }
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(ll i=n-1;i>=0;i--){    
        while(!s.empty() && arr[s.top()]>arr[i]){
            s.pop();
        }
        if(s.empty()){
            right[i]=n-i;
        }
        else{
            right[i]=s.top()-i;
        }
        s.push(i);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans+=(left[i]*right[i]*arr[i]);
    }
    cout<<ans;

}

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int odd=0;
    for(int i=0;i<n;i++){
        if(arr[i]&1) odd++;
    } 
    cout<<(odd&1?"NO\n":"YES\n");                
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    deque<ll> d;
    d.push_back(a[0]);
    bool sw = true;
    if(n%2!=0) sw = false;
    for(int i=1;i<n;i++){
        if(sw){
            d.push_front(a[i]);
        }else{
            d.push_back(a[i]);
        }
        sw = !sw;
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";
    return 0;
}



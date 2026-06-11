#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e9+7;

void solve(){
    int n; cin>>n;
    ll fat = 1;
    for (ll i=2; i<=n; i++)
        fat = (fat * i)%MAX;
    cout<<fat<<endl;
}

int main(){
    solve();
    Bye;
}
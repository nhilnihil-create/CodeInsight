#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    ll a, b, c, d; cin>>a>>b>>c>>d;

    ll area_1 = a*b;
    ll area_2 = c*d;

    cout<<(area_1>=area_2 ? area_1 : area_2)<<endl;
}

int main(){
    solve();
    Bye;
}
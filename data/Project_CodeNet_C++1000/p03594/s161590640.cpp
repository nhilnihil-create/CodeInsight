#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string print="RYGB";
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll h,w,d;cin>>h>>w>>d;

    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            ll x = (w+i+j)/d;
            x%=2;

            ll y = (w+i-j)/d;
            y%=2;

            cout<<print[2*x + y];
        }
        cout<<"\n";
    }
}




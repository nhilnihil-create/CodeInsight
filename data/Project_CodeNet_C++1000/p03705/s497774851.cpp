#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans=0;
    if(a>b){
        cout << 0 << endl;
        return 0;
    }
    if(n==1){
        if(a<b){
            cout << 0 << endl;
            return 0; 
        }
        else{
            cout << 1 << endl;
            return 0;
        }
    }

    ans = (b-a)*(n-2)+1;
    cout << ans << endl;



    return 0;
}
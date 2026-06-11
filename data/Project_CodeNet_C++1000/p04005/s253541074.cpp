
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a%2==0 || b%2==0 || c%2==0){
        cout << 0 << endl;
        return 0;
    }
    else{
        ll big=max(max(a,b),c);
        if(big==a){
            cout << b*c << endl;
            return 0;
        }
        else if(big==b){
            cout << a*c << endl;
            return 0;            
        }
        else if(big==c){
            cout << a*b << endl;
            return 0;            
        }
    }
}
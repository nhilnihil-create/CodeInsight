#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+sizeof(a)/sizeof(a[0]),greater<int>());
    
    bool x = false;
    bool y = false;
    int h = 0,w = 0;
    for(int i = 1;i < n;i++){
        
        if(!(x) && a[i] == a[i-1]){
            h = a[i];
            x = true;
            a[i] = 0;a[i-1] = 0;
            continue;
        }
        
        if(x && a[i] == a[i-1]){
            w = a[i];
            y = true;
            break;
        }
    }
    
    if(x && y){
        cout << (ll)h*w;
    }else{
        cout << 0;
    }
}



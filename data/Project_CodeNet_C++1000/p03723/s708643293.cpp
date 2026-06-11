#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int ans = -1;
    if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;i <= 1000;i++){
        if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0){
            ans = i-1;
            break;
        }
        int x,y,z;
        x = a;
        y = b;
        z = c;
        a = (y+z)/2;
        b = (x+z)/2;
        c = (x+y)/2;
    }
    cout << ans << endl;
}


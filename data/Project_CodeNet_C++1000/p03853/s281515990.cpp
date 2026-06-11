#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;




int main() {
    int n,k;
    cin >> n >> k;
    string a;
    for(int i = 0;i < n;i++){
        cin >> a;
        for(int j = 0;j < 2;j++){
            cout << a << endl;
        }
    }
    
}


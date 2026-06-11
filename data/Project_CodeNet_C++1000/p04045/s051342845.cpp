#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n,k; cin >> n >> k;
    int a[k];
    for(int i = 0;i < k;i++){
        cin >> a[i];
    }
    
    for(int i = n;i <= 100000;i++){
        string s = to_string(i);
        bool b = true;
        for(int j = 0;j < k;j++){
            if(s.find(to_string(a[j])) != string::npos){
                b = false;
                break;
            }
        }
        if(b){
            cout << s;
            break;
        }
    }
}


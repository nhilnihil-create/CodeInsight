#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int main(){
    ll n, i, j, k, mn, count = 0, flag = 0, res = 0;
    cin >> n;
    ll a[n][n] = {};
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            mn = a[i][j];
            for(k=0; k<n; k++){
                if(k == i || k == j) continue;
                if(a[i][j] > a[i][k] + a[k][j]){
                    flag = 1;
                    i = j = k = n;
                }else if(a[i][j] == a[i][k] + a[k][j]){
                    mn = 0;
                    k = n;
                }
            }
            res += mn;
        }
    }
    if(flag){
        cout << "-1\n";
    }else{
        cout << res << "\n";
    }    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[500][500];
bool memo[500][500];

signed main(){
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                if(a[j][k] > a[j][i] + a[i][k]){
                    cout << -1 << endl;
                    return 0;
                }else if(a[j][k] == a[j][i] + a[i][k] && i != j && i != k){
                    memo[j][k] = true;
                }
            }
        }
    }


    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!memo[i][j]){
                ans += a[i][j];
            }
        }
    }

    cout << ans/2 << endl;

    return 0;
}

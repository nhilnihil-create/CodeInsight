#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    ll field[350][350];
    ll ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> field[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            bool checker = true;
            for(int k = 1; k <= n; k++){
                if(k == i){
                    continue;
                }
                if(k == j){
                    continue;
                }
                if(field[i][j] > (field[i][k] + field[k][j])){
                    cout << -1 << endl;
                    return 0;
                }
                if(field[i][j] == (field[i][k] + field[k][j])){
                    checker= false;
                }
            }
            if(checker){
                ans += field[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
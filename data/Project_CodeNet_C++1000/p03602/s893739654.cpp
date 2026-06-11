#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[301][301];
bool use_a[301][301];

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(a[j][k] > a[j][i] + a[i][k]){
                    cout << "-1" << endl;
                    return 0;
                }

                if(a[j][k] == a[j][i] + a[i][k]  && a[j][i] && a[i][k] > 0){
                    use_a[j][k] = true;
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            if(use_a[i][j] == false){
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
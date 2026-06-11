#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){

    int N = 1000;
    vector<int> arr(N);
    vector<int> so(0);
    for(int i = 0; i < N; i++){
        arr[i] = 1;
    }
    for(int i = 2; i < sqrt(N); i++){
        if(arr[i]){
            for(int j = 0; i * (j + 2) < N; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(arr[i]){
            so.push_back(i);
        }
    }

    int n;
    cin >> n;
    vector<int> ya(n+1);
    rep(i, n+1) ya.at(i) = 1;
    for(int i=2; i<=n; i++){
        int k = i;
        rep(j, so.size()){
            while(k%so.at(j) == 0){
                k/=so.at(j);
                ya.at(so.at(j))++;
            }
        }
    }
    ll ans = 1;
    rep(i, n+1){
        ans *= ya.at(i);
        if(ans >= 1000000007) ans %= 1000000007;
    } 
    cout << ans << endl;
    return 0;
}
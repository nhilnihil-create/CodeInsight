#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
int main() {
    int W , H , N;
    cin >> W >> H >> N;
    int l = 0 , r = W , u = H , d = 0;
    rep(i , N){
        int x , y , a;
        cin >> x >> y >> a;
        if(a == 1){
            l = max(l , x);
        }
        if(a == 2){
            r = min(r , x);
        }
        if(a == 3){
            d = max(d , y);
        }
        if(a == 4){
            u = min(u , y);
        }   
    }
    cout << max(0 , r - l) * max(0 , u - d) << endl;
}

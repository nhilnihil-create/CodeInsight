#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int x, y;
    cin >> x >> y;
    int mini = INF;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int xx = x, yy = y;
            int cnt = 0;
            if(i == 0){
                xx = -1 * xx;
                cnt++;
            }
            if(j == 0){
                yy = -1 * yy;
                cnt++;
            }
            if(xx <= yy){
                mini = min(mini, yy - xx + cnt);
            }
        }
    }
    cout << mini << endl;
    return 0;
}

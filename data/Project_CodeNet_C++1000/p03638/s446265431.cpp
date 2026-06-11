#include <bits/stdc++.h>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define divceil(A, B) ((A + (B - 1)) / B)
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

typedef long long ll;

using namespace std;

int main(){

    int h, w, n;
    cin >> h >> w;
    cin >> n;

    vector<int> color;
    vector<vector<int>> ans(h, vector<int>(w));

    rep(i,n){
        int tmp;
        cin >> tmp;
        color.pback(tmp);
    }

    int x = 0;
    int y = 0;

    for(int i = 1; i <= n; i++){
        while(color[i - 1] > 0){
            ans[y][x] = i;

            if(y % 2 == 0){
                if(x == w - 1){
                    y++;
                }else{
                    x++;
                }
            }else{
                if(x == 0){
                    y++;
                }else{
                    x--;
                }
            }
            
            color[i - 1]--;
        }
    }

    rep(i,h){
        rep(j,w){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
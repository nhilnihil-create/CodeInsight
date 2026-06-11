#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int H, W;
    char c;
    cin >> H >> W;

    rep(i, H+2)
    {
        rep(j, W+2){
            if((i == 0) || (i == H+1)){
                cout << '#';
            }else{
                if ((j == 0) || (j == W+1)) {
                    cout << '#';
                }else{
                    cin >> c;
                    cout << c;
                }

            }
        }
        cout << endl;
    }
    return 0;
}
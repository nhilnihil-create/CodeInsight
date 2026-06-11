#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int h,w,k;
    cin >> h >> w >> k;
    int hpush,wpush;
    bool ok=false;
    rep(i,h+1){
        rep(j,w+1){
            hpush = i;
            wpush = j;
            int masu = hpush*w + (wpush*(h-hpush) - wpush*hpush);
            if(masu == k){
                ok =true;
            }
        }
    }
    if(ok) cout << "Yes" <<endl;
    else cout << "No" << endl;
} 
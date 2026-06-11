#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);

int main(){
    int a, b, c, d, e, f;
    sc(a) sc(b) sc(c) sc(d) sc(e) sc(f)
    int water[2] = {100*a, 100*b},sugar[2] = {c, d};
    int tmpw, tmps;
    P ans = P(0, 0);
    for (int i = 0; i <= 3000; i++){
        for (int j = 0; j <= 3000; j++){
            tmpw = water[0]*i + water[1]*j;
            if (tmpw > f) break;
            for (int x = 0; x <= 3000; x++){
                for (int y = 0; y <= 3000; y++){
                    tmps = sugar[0]*x + sugar[1]*y;
                    if (tmpw + tmps > f) break;
                    if (tmpw * e < tmps * 100) break;
                    if (ans.first == 0) ans = P(tmpw + tmps, tmps);
                    else if (ans.second*(tmpw+tmps) < \
                    tmps*ans.first) ans = P(tmpw + tmps, tmps);
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
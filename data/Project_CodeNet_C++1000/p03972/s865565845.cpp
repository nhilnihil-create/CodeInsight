#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;

    ll p[w], q[h];
    for(int i = 0; i < w; i++) cin >> p[i];
    for(int i = 0; i < h; i++) cin >> q[i];

    sort(p, p + w);
    sort(q, q + h);

    ll ans = 0;
    int idw = 0, idh = 0;
    int n = w + 1;
    int m = h + 1;
    while(idw != w || idh != h){
        if(idw == w){
            ans += q[idh] * n;
            m--;
            idh++;
        }
        else if(idh == h){
            ans += p[idw] * m;
            n--;
            idw++;
        }
        else if(p[idw] < q[idh]){
            ans += p[idw] * m;
            n--;
            idw++;
        }
        else {
            ans += q[idh] * n;
            m--;
            idh++;
        }
    }

    cout << ans << endl;
    return 0;
}
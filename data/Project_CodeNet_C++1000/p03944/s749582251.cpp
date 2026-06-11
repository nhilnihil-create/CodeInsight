#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    int w, h, n; sc(w), sc(h), sc(n);
    vector<int> x(n), y(n), a(n);
    rep(i, 0, n) sc(x[i]), sc(y[i]), sc(a[i]);

    int xr = 0, xl = w, yu = 0, yd = h, ans;
    rep(i, 0, n){
        if (a[i]==1) xr = max(xr, x[i]);
        if (a[i]==2) xl = min(xl, x[i]);
        if (a[i]==3) yu = max(yu, y[i]);
        if (a[i]==4) yd = min(yd, y[i]);
    }
    int sx = min(w, xr+w-xl), sy = min(h, yu+h-yd);
    cout << h*w - (sx*h + sy*w - sx*sy) << endl;
    return 0;
}
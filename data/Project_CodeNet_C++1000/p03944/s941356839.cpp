#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> X(n), Y(n), a(n);
    rep(i, n) cin >> X[i] >> Y[i] >> a[i];

    vector<int> img(w * h);
    rep(i, w * h) img[i] = 0;

    rep(i, n) {
        if (a[i] == 1) {
            rep(y, h) {
                for (int x = 0; x < X[i]; x++) {
                    img[y * w + x] = 1;
                }
            }
        }
        else if (a[i] == 2) {
            rep(y, h) {
                for (int x = X[i]; x < w; x++) {
                    img[y * w + x] = 1;
                }
            }
        }
        else if (a[i] == 3) {
            rep(x, w) {
                for (int y = 0; y < Y[i]; y++) {
                    img[y * w + x] = 1;
                }
            }
        }
        else {
            rep(x, w) {
                for (int y = Y[i]; y < h; y++) {
                    img[y * w + x] = 1;
                }
            }
        }
    }

    int cnt = 0;
    rep(i, img.size()) cnt += 1 - img[i];
    
    put(cnt)
    return 0;
}
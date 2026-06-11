#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int H, W;
    cin >> H >> W;


    int mi = 1e10;
    rep(i, H) {
        int h = i+1;

        if((H-h)%2==0 || W%2==0) {
            mi = min(mi, max(h*W, (H-h)*W/2)-min(h*W, (H-h)*W/2));
        } else {
            int th=(H-h)/2+1;
            int tth = th-1;
            int tw = W/2+1;
            int ttw = tw-1;
            mi = min(mi, max(h*W, th*W)-min(h*W, tth*W));
            mi = min(mi, max(h*W, (H-h)*tw) - min(h*W, (H-h)*ttw));
        }
    }

    rep(i, W) {
        int w = i+1;
        
        if((W-w)%2==0 || H%2==0) {
            mi = min(mi, max(w*H, (W-w)*H/2)-min(w*H, (W-w)*H/2));
        } else {
            int th = H/2+1;
            int tth = th-1;
            int tw = (W-w)/2+1;
            int ttw = tw-1;
            mi = min(mi, max(H*w, H*tw) - min(H*w, H*ttw));
            mi = min(mi, max(H*w, th*(W-w)) - min(H*w, tth*(W-w)));
        }
    }

    cout << mi << endl;

    return 0;
}
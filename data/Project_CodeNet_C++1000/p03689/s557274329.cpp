#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
    int i, j, h, w, H, W, mh, mw;
    scanf("%d%d%d%d", &H, &W, &h, &w);
    if(H%h==0 && W%w==0) {
        printf("No\n");
        return 0;
    }
    if(H%h) mh=h, mw=1;
    else mh=1, mw=w;
    printf("Yes\n");
    for(i=1; i<=H; i++) for(j=1; j<=W; j++)
        printf(j==W? "%d\n" : "%d ",
            (i%mh==0 && j%mw==0? -(mh+mw-2)*1000-1 : 1000));
    return 0;
}
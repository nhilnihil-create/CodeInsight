#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<x<<endl;
#define Nmax 500005
using namespace std;

ll n, ans, a, b, H, W, h, w;
string s;

int main()
{
    cin >> H >> W >> h >> w;

    if (H % h){
        cout << "Yes\n";
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                if (i%h==0) cout << 1000 * (h-1) - 1 << ' ';
                else cout << -1000 << ' ';
            }
            cout << '\n';
        }
    }
    else if (W % w){
        cout << "Yes\n";
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                if (j%w==0) cout << 1000 * (w-1) - 1 << ' ';
                else cout << -1000 << ' ';
            }
            cout << '\n';
        }
    }
    else{
        cout << "No\n";
    }
    return 0;
}

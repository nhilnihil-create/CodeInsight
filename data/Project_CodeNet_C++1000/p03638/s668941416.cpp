//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e4 + 5;
const int OO = 2e9;

int h,w,n,a[N],ans[101][101];

void init() {



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n;

    for(int i=0;i<n;++i) {

        cin >> a[i];

    }

    int cur = 0;

    for(int i=0;i<h;++i) {

        if(i&1) {

            for (int j = 0; j < w; ++j) {

                if (!a[cur]) ++cur;
                ans[i][j] = cur + 1;
                a[cur]--;

            }

        } else {

            for (int j = w-1; j >= 0; --j) {

                if (!a[cur]) ++cur;
                ans[i][j] = cur + 1;
                a[cur]--;

            }

        }

    }

    for(int i=0;i<h;++i) {

        for(int j=0;j<w;++j) {

            cout << ans[i][j] << ' ';

        }

        cout << '\n';

    }

    return 0;

}
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    int N;
    cin >> N;
    int free = 0;
    vector<bool> validColor(8, false);
    REP (i, N) {
        int a;
        cin >> a;
        int color = a / 400;
        if (color > 7) {
            free++;
        } else {
            validColor[color] = true;
        }
    }
    int c = count(validColor.begin(), validColor.end(), true);
    int ans1 = max(c, 1);
    int ans2 = c + free;

    cout << ans1 << " " << ans2 << endl;

    return 0;
}
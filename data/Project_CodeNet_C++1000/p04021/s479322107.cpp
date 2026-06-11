#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, a[100003], p, ans;
    vector<int> ap;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        ap.push_back(a[i]);
    }

    sort(ap.begin(), ap.end());

    ans = 0;
    for (i = 0; i < n; i++) {
        p = lower_bound(ap.begin(), ap.end(), a[i]) - ap.begin();
        if (abs(p - i) % 2 == 1) {
            ans++;
        }
    }

    printf("%d\n", ans / 2);

    return 0;
}
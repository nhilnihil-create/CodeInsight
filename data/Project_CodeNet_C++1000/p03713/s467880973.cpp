#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long h, w, t;
    cin >> h >> w;

    long long ans, minans = 1e5, maxsq, minsq;
    for (int j=0; j<2; ++j) {
        for (long long i=1; i < h; ++i) {
            maxsq = max(w*i, max((h-i)*(w/2), (h-i)*(w/2) + (h-i)*(w&1)));
            minsq = min(w*i, min((h-i)*(w/2), (h-i)*(w/2) + (h-i)*(w&1)));
            ans = maxsq - minsq;
            //cout << maxsq << " " << minsq <<endl;
            if (ans < minans)
                minans = ans;
        }

        for (long long i=1; i < h; ++i) {
            maxsq = max(w*i, max(((h-i)/2)*w, ((h-i)/2)*w + w*((h-i)&1)));
            minsq = min(w*i, min(((h-i)/2)*w, ((h-i)/2)*w + w*((h-i)&1)));
            ans = maxsq - minsq;
            //cout << maxsq << " " << minsq <<endl;
            if (ans < minans)
                minans = ans;
        }
        t = w;
        w = h;
        h = t;
    }

    cout << minans;

}

int main() {
    solve();
    return 0;
}

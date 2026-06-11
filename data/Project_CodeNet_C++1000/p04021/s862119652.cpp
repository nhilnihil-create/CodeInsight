#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    //compress
    vector<int> hoge;
    rep(i,n) hoge.push_back(a[i]);
    sort(hoge.begin(), hoge.end());
    for (int i = 0; i < n; ++i) {
        int it = lower_bound(hoge.begin(), hoge.end(), a[i]) - hoge.begin();
        a[i] = it;
    }

    int res = 0;
    rep(i,n) {
        if(a[i] & 1) {
            res += (a[i] + i) % 2;//if(i%2 != a[i]%2)
        }
    }
    cout << res << endl;
    return 0;
}
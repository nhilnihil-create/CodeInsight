#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repi(i, n, k) for(int i = k; i < n; ++i)
typedef long long int ll;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int a[100010];
    int b[100010] = {};
    
    rep(i, n) {
        cin >> a[i];
        if(a[i] > 0) b[a[i] - 1] += 1;
        b[a[i]] += 1;
        b[a[i] + 1] += 1;
    }
    
    int res = 0;
    rep(i, 100000) res = max(res, b[i]);
    cout << res << endl;
    
    
}


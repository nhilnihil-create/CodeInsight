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
    long long int c, k;
    long long int t[100010];
    
    cin >> n >> c >> k;
    rep(i, n) cin >> t[i];
    sort(t, t + n);
    
    int ans = 1;
    long long int cusnum = 0;
    
    long long int genkai = t[0] + k;
    
    rep(i, n) {
        
        if(cusnum < c && t[i] <= genkai) {
            ++cusnum;
        }
        else {
            genkai = t[i] + k;
            cusnum = 1;
            ++ans;
        }
    }
    
    cout << ans << endl;
}

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans = min(n, k) * x + max(n - k, 0) * y;
    cout << ans << endl;
}

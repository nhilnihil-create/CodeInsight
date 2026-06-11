#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    int cur = 1;
    for(; ans <= n; ans++){
        if(cur == 2) break;
        else cur = a[cur];
    }

    if(ans > n) ans = -1;
    cout << ans << endl;
    return 0;
}
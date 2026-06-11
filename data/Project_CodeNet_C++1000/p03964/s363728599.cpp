#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    long int n;
    cin >> n;
    long int t[n], a[n];
    rep(i, n) cin >> t[i] >> a[i];
    long int ans1 = t[0], ans2 = a[0];
    for(int i = 1; i < n; i++){
        long int m;
        if(ans1 % t[i] == 0) m = ans1 / t[i];
        else m = ans1 / t[i] + 1;

        if(ans2 % a[i] == 0) m = max(m, ans2 / a[i]);
        else m = max(m, ans2 / a[i] + 1);

        ans1 = t[i] * m;
        ans2 = a[i] * m;
    }
    cout << ans1 + ans2 << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];

    vector<bool> from1(n+1, false), ton(n+1, false);
    for(int i = 0; i < m; i++){
        if(a[i] == 1) from1[b[i]] = true;
        if(b[i] == n) ton[a[i]] = true;
    }

    string ans = "IMPOSSIBLE";
    for(int i = 1; i <= n; i++){
        if(from1[i] && ton[i]) ans = "POSSIBLE";
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    for(int i = 0; i < m; i++) cin >> p[i] >> x[i];

    int ans = 0;
    for(int i = 0; i < n; i++) ans += t[i];
    for(int i = 0; i < m; i++){
        cout << ans - t[p[i]-1] + x[i] << endl;
    }
    return 0;
}
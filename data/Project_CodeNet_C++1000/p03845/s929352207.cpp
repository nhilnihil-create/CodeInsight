#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int m;
    cin >> m;
    vector <int> p(m),x(m);
    for(int i = 0; i < m; i++){
        cin >> p[i] >> x[i];
        p[i]--;
    }
    for(int i = 0; i < m; i++){
        long ans = 0;
        for(int j = 0; j < n; j++){
            if(j==p[i]){
                ans += x[i];
            }else{
                ans += t[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
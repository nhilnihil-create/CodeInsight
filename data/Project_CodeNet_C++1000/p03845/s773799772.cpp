/*
      author  : nishi5451
      created : 12.08.2020 22:03:33
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n;
    vector<int> t(n+1);
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> t[i];
        sum += t[i];
    }
    cin >> m;
    vector<int> p(m+1),x(m+1);
    for(int i=1; i<=m; i++){
        cin >> p[i];
        cin >> x[i];
    }
    for(int i=1; i<=m; i++)
        cout << sum-t[p[i]]+x[i] << endl;
    return 0;
}
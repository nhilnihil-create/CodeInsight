/*
      author  : nishi5451
      created : 14.08.2020 12:53:27
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    for(int i=1; i<=n; i++)
        cout << v[i] << endl;
    return 0;
}
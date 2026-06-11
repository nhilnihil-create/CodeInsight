/*
      author  : nishi5451
      created : 12.08.2020 22:00:31
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w;
    cin >> h >> w;
    vector<char> a(w);
    rep(i,h) {
        rep(j,w) cin >> a[j];
        rep(repeat,2){
            rep(j,w) cout << a[j];
            cout << endl;
        }
    }

    return 0;
}
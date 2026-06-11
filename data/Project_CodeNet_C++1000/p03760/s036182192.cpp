/*
      author  : nishi5451
      created : 12.08.2020 23:47:42
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string o,e;
    cin >> o >> e;
    rep(i,int(e.size())){
        cout << o[i] << e[i];
    }
    if(o.size() > e.size())
        cout << o.back();
    cout << endl;

    return 0;
}
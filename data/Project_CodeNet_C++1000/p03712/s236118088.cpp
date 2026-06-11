/*
      author  : nishi5451
      created : 14.08.2020 13:03:33
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w;
    cin >> h >> w;
    rep(i,w+2) cout << "#";
    cout << endl;
    rep(i,h){
        cout << "#";
        string s;
        cin >> s;
        cout << s;
        cout << "#" << endl;
    }
    rep(i,w+2) cout << "#";
    cout << endl;
    return 0;
}
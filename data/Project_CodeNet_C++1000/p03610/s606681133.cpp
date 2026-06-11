/*
      author  : nishi5451
      created : 14.08.2020 14:52:40
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string ans;
    rep(i,int(s.size())){
        if(!(i&1)){
            ans+=s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
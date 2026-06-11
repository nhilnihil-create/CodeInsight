/*
      author  : nishi5451
      created : 12.08.2020 23:44:07
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<int> s(3);
    rep(i,3) cin >> s[i];
    sort(s.begin(),s.end());
    if(s[0]==5 && s[1]==5 && s[2]==7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
/*
      author  : nishi5451
      created : 14.08.2020 14:23:07
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string ans;
    ans.push_back(s.front());
    ans+=to_string(int(s.size()-2));
    ans.push_back(s.back());
    cout << ans << endl;
    return 0;
}
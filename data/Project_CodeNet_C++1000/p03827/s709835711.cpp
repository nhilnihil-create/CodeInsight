/*
      author  : nishi5451
      created : 12.08.2020 22:15:41
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    string s;
    cin >> n >> s;
    int now = 0;
    int mx = 0;
    rep(i,n){
        if(s[i]=='I') now++;
        else if(s[i]=='D') now--;
        mx = max(now,mx);
    }
    cout << mx << endl;
    return 0;
}

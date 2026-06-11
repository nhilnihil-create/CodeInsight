/*
      author : nishi5451
      created: 12.08.2020 00:19:05
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    int h,w;
    cin >> h >> w;
    rep(i,h){
        rep(j,w){
            cin >> s;
            if(s=="snuke"){
                cout << char('A'+j) << 1+i << endl;
            }
        }
    }
    return 0;
}
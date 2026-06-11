/*
      author  : nishi5451
      created : 12.08.2020 22:27:22
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m; 
    cin >> n >> m;
    vector<string> s,t;
    rep(i,n){
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    rep(i,m){
        string tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    rep(i,n-m+1){
        rep(j,n-m+1){
            bool check = true;
            rep(k,m){
                if(s[i+k].substr(j,m)!=t[k]){
                    check = false;
                    break;
                }
            }
            if(check==true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
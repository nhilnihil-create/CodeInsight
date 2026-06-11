/*
      author : nishi5451
      created: 12.08.2020 16:12:44
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string a;
    rep(i,(int)s.size()){
        if(s[i]=='0') a.push_back('0');
        else if(s[i]=='1') a.push_back('1');
        else if(s[i]=='B'){
            if(!a.empty())
                a.pop_back();
        } 
    }
    cout << a << endl;
    return 0;
}

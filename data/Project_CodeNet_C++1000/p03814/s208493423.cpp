#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s;
    cin >> s;

    int r(0),l(-1);
    rep(i,s.size()){
        if(l==-1 && s[i]=='A'){
            l = i;
        }
        if(s[i]=='Z'){
            r = i;
        }
    }

    cout << r-l+1 << endl;

    return 0;
}
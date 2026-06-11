#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string s,t;
    cin >> s;
    t="CODEFESTIVAL2016";
    int ans=0;
    
    for(int i=0;i<t.length();i++){
        if(s[i]!=t[i]) ans++;
    }
    
    cout << ans << endl;

    return 0;
}






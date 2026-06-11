#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    string s;
    stringstream ss;

    cin >> s ;

    ss << s[0]; 
    ss << s.size()-2;
    ss << s[s.size()-1];

    string ans = ss.str();

    cout << ans << endl;


}

    

#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    string S;
    cin >> S;
    
    string s = S.substr(0,4);
    if(s == "YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

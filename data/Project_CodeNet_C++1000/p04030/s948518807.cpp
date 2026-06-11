#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    string ans="";
    rep(i, s.size()){
        if(s[i] =='1' || s[i]=='0') ans.push_back(s[i]);
        else if(s[i]=='B' && ans.size() !=0){
            ans.erase(ans.size()-1);
        }
    }
    cout << ans << endl;
    return 0;
}
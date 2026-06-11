//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>

int main(){
    string s;
    cin >> s;
    string ans;
    rep(i,0,s.size()){
        if(s[i]=='0' || s[i]=='1') ans.push_back(s[i]);
        else if(ans.size()!=0 && s[i]=='B') ans.pop_back();
    }
    cout << ans << endl;
    return 0;
}
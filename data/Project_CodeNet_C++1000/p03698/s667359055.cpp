#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    string s;
    cin >> s;
    string ans= "yes";
    rep(i,s.size()){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                ans ="no";
            }
        }
    }
    cout << ans << endl;
    return 0;
    }
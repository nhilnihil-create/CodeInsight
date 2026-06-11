#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int n;

bool dfs(const string &s,int i){
    if(i==n) return true;

    if(s.substr(i,5) == "erase"){
        if(dfs(s,i+5)) return true;
        else if(s[i+5] == 'r') {
            if(dfs(s,i+6)) return true;
        }else return false;
    }else if(s.substr(i,5) == "dream"){
        if(dfs(s,i+5)) return true;
        else if(s[i+5] == 'e'&&s[i+6] == 'r') {
            if(dfs(s,i+7)) return true;
        }else return false;
    }

    return false;
}
int main(){
    string s;
    cin >> s;
    n = s.size();

    if(dfs(s,0)) cout <<"YES"<<endl;
    else cout << "NO"<<endl;
 }

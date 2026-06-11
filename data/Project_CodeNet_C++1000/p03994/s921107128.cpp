#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int main(){
    string s;
    cin >> s;
    int k;
    cin >>k;

    string ans = "";
    rep(i,s.size()){
        int d = 26 - (s[i]-'a');

        if(i == s.size()-1){
            char ch = (s[i] - 'a' + k%26)%26 + 'a';
            ans.push_back(ch);
            break;
        }
        if(k >= d && d != 26){
            ans.push_back('a');
            k -= d;
        }else{
            ans.push_back(s[i]);
        }
    }

    cout << ans << endl;
}
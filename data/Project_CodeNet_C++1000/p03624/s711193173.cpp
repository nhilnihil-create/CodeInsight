#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    rep(i,s.size()){
        cnt[s[i]-'a'] = 1;
    }
    rep(i,26){
        if(cnt[i]!=1) {
            printf("%c\n", 'a'+i);
            return 0;
            }
    }
    cout << "None" << endl; 
    return 0;
}
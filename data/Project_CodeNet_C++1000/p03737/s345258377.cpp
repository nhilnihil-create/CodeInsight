#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    vector<string> s(3);
    rep(i,3)cin>>s[i];
    rep(i,3)cout<<(char)toupper(s[i][0]);
    cout << endl;
    
    return 0;
}
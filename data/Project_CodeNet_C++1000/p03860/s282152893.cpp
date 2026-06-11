#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    string ans = "A";
    ans += s[1][0]; 
    ans += 'C';
    cout << ans << endl;
}
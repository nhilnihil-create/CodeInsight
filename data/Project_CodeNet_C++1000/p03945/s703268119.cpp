#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    string s;
    cin >> s;
    int n = s.size();
    queue<char> que;
    que.push(s[0]);
    rep(i,n-1){
        if(s[i]!=s[i+1]) que.push(s[i+1]);
    }
    cout << que.size()-1 << endl;

}
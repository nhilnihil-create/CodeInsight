#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    int n; cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int MAX = 0;
    rep(i, n){
        if(s[i] == 'D') cnt--;
        else if(s[i] == 'I') cnt++;
        MAX = max(MAX, cnt);
    }
   cout << MAX << endl;
}
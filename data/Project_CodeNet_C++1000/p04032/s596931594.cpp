#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i+1]){
            cout << i + 1 << " " << i+1 + 1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < s.size() - 2; i++){
        if(s[i] == s[i+2]){
            cout << i + 1 << " " << i+2 + 1 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string w;
    cin >> w;
    map<int, int>mp;
    rep(i,w.size()){
        mp[w[i]-'a']++;
    }
    rep(i,26){
        if(mp[i]%2==1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
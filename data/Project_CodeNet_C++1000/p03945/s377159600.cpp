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
    vector<char> w, b;
    int cnt = 0;
    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] != s[i+1]) cnt++;
    }
    cout << cnt << endl;
}
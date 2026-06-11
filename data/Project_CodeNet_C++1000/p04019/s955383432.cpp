#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> s1;
    map<char, int> m;
    rep(i, s1.length()){
        m[s1[i]]++;
    }
    bool flag = true;
    if(m['N'] == 0 && m['S'] != 0) flag = false;
    if(m['N'] != 0 && m['S'] == 0) flag = false;
    if(m['W'] == 0 && m['E'] != 0) flag = false;
    if(m['E'] == 0 && m['W'] != 0) flag = false;
    if(flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}
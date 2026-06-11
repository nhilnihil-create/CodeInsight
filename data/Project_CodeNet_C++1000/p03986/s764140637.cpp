#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    string str; cin >> str;
    stack<char> st;
    int ans = 0;
    rep(i, str.length()){
        if(str[i] == 'S')st.push('S');
        else{
            if(st.size() == 0) ans++;
            else st.pop();
        }
    }
    cout << ans + st.size() << endl;
}
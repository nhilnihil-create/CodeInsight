#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    set<char> st;
    rep(i,s.size()) st.insert(s[i]);
    if (st.size()==s.size()) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

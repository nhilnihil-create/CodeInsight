#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    string s;
    cin>>n>>s;
    stack<char> st;
    int cnt=0;
    rep(i,n){
        if(s[i]=='(') st.push('(');
        else{
            if(!st.empty()){
                st.pop();
            }
            else cnt++;
        }
    }

    string ans="";
    rep(i,cnt) ans+='(';
    ans+=s;
    rep(i,st.size()) ans+=')';

    cout<<ans<<endl;
}
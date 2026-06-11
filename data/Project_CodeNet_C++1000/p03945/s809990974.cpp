#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    stack<char>q;
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(q.empty() || q.top()!=s[i])q.push(s[i]);
    }
    co(q.size()-1);
}
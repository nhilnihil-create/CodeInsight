#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
string s;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>s;
    ll sum=0;
    ll now;
    for(int bit=0;bit<(1<<s.size()-1);++bit){
        now=0;
        rep(i,s.size()){
            now=now*10+s[i]-'0';
            if(bit&(1<<i)){
                sum+=now;
                now=0;
            }
        }
        sum+=now;
    }
    cout<<sum<<endl;

    return 0;
}

#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(void){
    string s;
    
    cin>>s;
    char t=s[0];
    ll cnt=0;
    for(ll i=1;i<s.length();++i){
        if(t!=s[i]){
            cnt++;
            t=s[i];
        }
    }
    cout<<cnt;
    return 0;
}

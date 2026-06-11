#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    string s;cin>>s;
    char c=s[0];
    int ans=0;
    for(int i=1;i<s.length();++i){
        if(s[i]!=c){
            ans++;
            c=s[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
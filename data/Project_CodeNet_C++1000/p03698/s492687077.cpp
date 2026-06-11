#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    size_t l=s.length();
    map<char,int> dict;

    bool flag=true;
    rep(i,l){
        dict[s[i]]++;
        if(dict[s[i]]>=2){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"yes"<<"\n";
    else cout<<"no"<<"\n";
    return 0;
}
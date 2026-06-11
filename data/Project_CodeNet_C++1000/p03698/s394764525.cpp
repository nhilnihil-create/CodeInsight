#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    string s;
    cin>>s;
    map<char,int> mp;
    rep(i,0,s.size()){
        mp[s[i]]++;
        if(mp[s[i]]>1){cout<<"no"<<endl;return 0;}
    }
    cout<<"yes"<<endl;
    return 0;
}
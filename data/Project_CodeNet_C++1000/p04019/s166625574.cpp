#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int flag=1;
    string s;
    map<char,int> mp;
    cin >> s;
    rep(i,s.length()){
        mp[s[i]]++;
    }
    if(mp.count('E')!=mp.count('W'))flag=0;
    if(mp.count('N')!=mp.count('S'))flag=0;
    if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}

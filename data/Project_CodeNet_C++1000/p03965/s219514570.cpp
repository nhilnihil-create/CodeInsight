#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    int ans=0;
    ans+=s.size()/2-m['p'];
    cout << ans << endl;
}
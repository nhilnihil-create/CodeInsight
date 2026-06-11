#include <bits/stdc++.h>
using namespace std;
string s,t,ss;
long long n,m;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s>>t;

for(int i=0;i<t.size();i++){
        cout<<s[i]<<t[i];
}
if(s.size()!=t.size())cout<<s[s.size()-1];





return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;char ch[3128];
int main(){
    cin>>s;ch['p']='q',ch['q']='p',ch['b']='d',ch['d']='b';
    for(register int i=0;i<s.size();i++) if(s[s.size()-i-1]!=ch[s[i]]) puts("No"),exit(0);
    puts("Yes");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
    getline(cin,s1);
    s2=s1;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s2.size();++i)
        s2[i]=='b'?s2[i]='d':s2[i]=='d'?s2[i]='b':s2[i]=='p'?s2[i]='q':s2[i]='p';
    if(s1==s2)  puts("Yes");
    else    puts("No");
    return 0;
}
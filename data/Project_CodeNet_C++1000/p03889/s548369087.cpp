#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
int main(){
    cin>>s;
    string s1(s);
    reverse(s.begin(),s.end());
    rep(i,0,(int)s.size()-1){
        if(s1[i]=='b')s1[i]='d';
        else if(s1[i]=='d')s1[i]='b';
        else if(s1[i]=='p')s1[i]='q';
        else if(s1[i]=='q')s1[i]='p';
    }
    if(s1==s)printf("Yes");
    else printf("No");
    return 0;
}
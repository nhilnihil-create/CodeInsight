#include<bits/stdc++.h>
using namespace std;
string s,b;
int main(){
    cin>>s;
    b=s;reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
        switch(s[i]){
            case 'b':s[i]='d';break;
            case 'd':s[i]='b';break;
            case 'p':s[i]='q';break;
            case 'q':s[i]='p';break;
        }
    s==b?puts("Yes"):puts("No");
    return 0;
}
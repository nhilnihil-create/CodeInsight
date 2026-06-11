#include<bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<e;++i)

int main()
{
    string s,t;
    cin >> s;
    int cntg=0,cntp=0;
    F(i,0,s.size()){
        char ch='g';
        if(cntp+1<=cntg){
            ch='p';
        }
        if(ch=='g') cntg++;
        else cntp++;
        t+=ch;
    }
    int ans=0;
    F(i,0,s.size()){
        if(s[i]=='g' && t[i]=='p') ans++;
        if(s[i]=='p' && t[i]=='g') ans--;
    }
    cout << ans << endl;
    return 0;
}
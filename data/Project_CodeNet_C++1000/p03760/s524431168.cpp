#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s,s2;
    cin>>s>>s2;

    char c[200];
    memset(c,'1',sizeof(c));
    int j=0;

    for(int i=0;i<s.size(); i++){
        c[j]=s[i];
        j+=2;
    }
    j=1;
    for(int i=0; i<s2.size(); i++){
        c[j]=s2[i];
        j+=2;
    }
    for(int i=0; i<200; i++){
        if(c[i]!='1')
             cout<<c[i]<<"";
    }
    return 0;
}

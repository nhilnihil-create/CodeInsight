#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int N;
    cin>>N;
    string s;
    cin>>s;
    int x = 0,m = 0;
    for(int i = 0; i<N; i++){
        if(s[i]=='I')x+=1;
        else if(s[i]=='D')x-=1;
        m = max(x,m);
    }
    cout<<m;
    return 0;
}

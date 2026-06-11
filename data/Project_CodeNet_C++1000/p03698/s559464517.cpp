#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define endl '\n'
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    set<char>a;
    for(int i = 0; i<len; i++){
        a.insert(s[i]);
    }
    int m = a.size();
    if(len != m)puts("no");
    else puts("yes");
    return 0;
}

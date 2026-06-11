#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;cin>>a>>b>>c;
    char e =(max(a,b)-min(a,b))<(max(a,c)-min(a,c))?'A':'B';
    cout<<e;
    return 0;
}

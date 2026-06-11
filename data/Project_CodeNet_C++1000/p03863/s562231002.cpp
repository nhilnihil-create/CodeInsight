#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    if((a.length()%2==1)^(a[a.length()-1]==a[0])==1)cout<<"First\n";
    else cout<<"Second\n";
    return 0;
}
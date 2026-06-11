#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    string s,s2;
    cin>>s;
    sort(s.begin(),s.end());
    char a;a='a';
    for(int i=0;i<s.size();i++){
        if(s[i]==a)a+=1;
    }
    if(a!='{')cout<<a;
    else cout<<"None";

    return 0;
}

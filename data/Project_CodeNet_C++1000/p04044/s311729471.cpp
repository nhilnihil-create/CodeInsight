#include<bits/stdc++.h>
using namespace std;
bool compare(string a, string b)
    {
        return (a+b < b+a);
    }
int main()
{
    int x,l;
    cin>>x>>l;
    string s[111];
    for (int i=0;i<x;i++){
        cin>>s[i];
    }
    
    sort(s, s+x, compare);

    for (int i = 0; i < x; i++){
             cout<<s[i];

    }
    cout<<endl;
    
}
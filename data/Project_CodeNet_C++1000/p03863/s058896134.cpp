#include <bits/stdc++.h>

using namespace std;
 
string s;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    int n = s.length();
    
    if ((s[0]==s[n-1]) - n%2) cout<<"First"; else cout<<"Second";
    
    return 0;
}
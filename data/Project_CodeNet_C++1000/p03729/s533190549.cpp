#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[100],t[100],b[100];
    cin>>s>>t>>b;
    if((s[strlen(s)-1]==t[0]) && (t[strlen(t)-1]==b[0]))
     cout<<"YES";
    else 
     cout<<"NO";
     return 0;
}
     
   



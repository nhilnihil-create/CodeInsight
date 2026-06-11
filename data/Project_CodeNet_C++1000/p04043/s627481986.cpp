#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==7 && b==5 && b==c || b==7 && a==5 && c==a || c==7 && a==5 && b==a) cout<<"YES\n";
    else cout<<"NO\n";
    
    return(0);
}
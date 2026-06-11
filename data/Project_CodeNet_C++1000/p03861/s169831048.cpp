#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    lol a,b,x;
    cin>>a>>b>>x;
    if(a%x!=0)
        cout<<(b/x)-(a/x)<<"\n";
    else cout<<(b/x)-(a/x)+1<<"\n";
    return(0);
}
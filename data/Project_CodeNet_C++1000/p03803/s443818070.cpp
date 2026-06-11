#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a==1) a+=13;
    if(b==1) b+=13;
    if(a>b) cout<<"Alice\n";
    else if(a==b) cout<<"Draw\n";
    else cout<<"Bob\n";
    

    return(0);
}
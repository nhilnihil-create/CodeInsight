#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b,c[7]={1,3,5,7,8,10,12},d[4]={4,6,9,11},ai=0,bi=0;
    string s,t,q;
    cin>>a>>b;
    for(int i=0;i<7;i++){
        if(a==c[i])ai++;
        if(b==c[i])bi++;
    }
    if(ai==0 && bi==0){
        for(int i=0;i<4;i++){
            if(a==d[i])ai++;
            if(b==d[i])bi++;
        }
    }
    if(ai==bi) cout<<"Yes\n";
    else cout<<"No\n";
    return(0);
}
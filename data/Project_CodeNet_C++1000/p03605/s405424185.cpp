#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,t=0,r;
    cin>>n;
    while(n){
        r=n%10;
        if(r==9)
         {cout<<"Yes";t++;break;}
        n=n/10;
    }
    if(t==0)
     cout<<"No";
    return 0;
}
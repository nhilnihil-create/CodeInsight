#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,t; cin>>n;
    t=n;
    int r=0;
    while(t){
        int d=t%10;
        r=r*10+d;
        t/=10;
    }

    if(r==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}
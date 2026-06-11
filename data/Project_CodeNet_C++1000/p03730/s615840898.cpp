#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;cin>>a>>b>>c;
    int flag=0;
    for(int i=0;i<=100;i++){
        if((i*a)%b==c) flag=1;
    }
    if(flag==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
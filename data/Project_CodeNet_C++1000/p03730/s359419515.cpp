#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;cin>>a>>b>>c;
    bool res=0;
    for(int i=1;i<b;i++){
        if(a*i%b==c)res=1;
    }
    if(res)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
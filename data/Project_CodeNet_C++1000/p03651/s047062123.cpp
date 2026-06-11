#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,a,ak,h;
    cin>>n>>k>>a;
    h=a;
    for(int i=2;i<=n;i++){
        cin>>ak;
        a=__gcd(a,ak);
        h=max(ak,h);
    }
    if(k%a==0&&k<=h){
        cout<<"POSSIBLE"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
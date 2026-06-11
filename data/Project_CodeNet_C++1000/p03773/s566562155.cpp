#include<iostream>
using namespace std;
int mod(int n){
    return n%24;
}
int main(){
    int a,b,ans;
    cin>>a>>b;
    ans=mod(a+b);
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    long long ans;
    if(m>=2*n){
        ans=n+(m-2*n)/4;
    }else{ans=m/2;}
    cout<<ans<<endl;
    return 0;
}
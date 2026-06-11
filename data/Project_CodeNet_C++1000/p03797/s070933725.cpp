#include<iostream>
using namespace std;
int main(){
    unsigned long long int n,m;
    cin>>n>>m;
    if(m/2<=n){
        cout<<m/2;
    }
    else{
        unsigned long long int result=n;
        m-=2*n;
        result+=m/4;
        cout<<result;
    }
}
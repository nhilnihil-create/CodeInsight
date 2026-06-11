#include<iostream>
using namespace std;
long long int n,m,nd;
int main(){
    cin>>n>>m;
    nd=2*n;
    if(nd>m)cout<<m/2<<endl;
    else if(nd==m)cout<<n<<endl;
    else{
        m-=nd;
        m/=4;
        cout<<n+m<<endl;
    }
    return 0;
}
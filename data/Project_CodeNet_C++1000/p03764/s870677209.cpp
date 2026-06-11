#include <iostream>
using namespace std;
int main(void){
    long long n,m,x=0,y=0,p=1e9+7;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        long long z;
        cin>>z;
        if(i==1){
            x+=(1-n)*z;
        }else{
            x+=(2*i-n-1)*z;
        }
        x=(x+p*p)%p;
    }
    for(long long i=1;i<=m;i++){
        long long z;
        cin>>z;
        if(i==1){
            y+=(1-m)*z;
        }else{
            y+=(2*i-m-1)*z;
        }
        y=(y+p*p)%p;
    }
    cout<<(x*y)%p<<endl;
}

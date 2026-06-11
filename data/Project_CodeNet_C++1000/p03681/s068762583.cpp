#include<iostream>
using namespace std;
const int mod=1e9+7;
int fact(int n,long long int result){

    for(int i=2;i<=n;i++){
        result=result*i;
        result%=mod;
    }
    return result;
}
int main(){
    int n,m;
    cin>>n>>m;
    if(n<m){
        int temp=n;
        n=m;
        m=temp;
    }
    int result=1;
    if(n-m>1){
        cout<<"0"<<endl;
    }
    else{
        if(n==m)
            result=result*2;
        result=fact(n,result);
        result=fact(m,result);
        cout<<result<<endl;
    }
}
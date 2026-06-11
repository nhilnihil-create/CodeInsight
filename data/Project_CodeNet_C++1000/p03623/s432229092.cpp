#include<iostream>
using namespace std;

int main(){

    int x , a , b ;
    cin>>x>>a>>b;

    int aD=abs(x-a);
    int bD=abs(x-b);

    if(aD < bD) cout<<"A"<<endl;
    else cout<<"B"<<endl;


    return 0;
}
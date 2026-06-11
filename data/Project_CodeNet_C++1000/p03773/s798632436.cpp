#include<iostream>
using namespace std;
int mod(int n){
    return n%24;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<mod(a+b)<<endl;
    return 0;
}
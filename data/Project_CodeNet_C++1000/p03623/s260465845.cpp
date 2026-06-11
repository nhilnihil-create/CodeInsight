#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(x-a)>abs(x-b))cout<<"B"<<endl;
    else cout<<"A"<<endl;
    return 0;
}
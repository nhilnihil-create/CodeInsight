#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*b>=c*d)cout<<a*b<<endl;
    else cout<<c*d<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a,b,h;
    cin>>a>>b>>h;
    if(a+b==h||a+h==b||h+b==a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

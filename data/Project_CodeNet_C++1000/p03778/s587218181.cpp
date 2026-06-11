#include<iostream>
using namespace std;
int main()
{
    int w,a,b,c,d;
    cin>>w>>a>>b;
    c=a+w;
    d=b+w;
    if(c<b){
        cout<<b-c<<endl;
    }
    else if(a>d){
        cout<<a-d<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(a>0&&b>0)cout<<"Positive"<<endl;
    else if(a<=0&&b>=0)cout<<"Zero"<<endl;
    else if(a<0&&b<0){
        if((b-a)%2==0&&b!=a)cout<<"Negative"<<endl;
        else cout<<"Positive"<<endl;
    }
    return 0;
}
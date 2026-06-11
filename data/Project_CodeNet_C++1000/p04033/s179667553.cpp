#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(((a<0)&&(b>0))||a==0||b==0){
        cout<<"Zero"<<endl;
        return 0;
    }
    if(a>0){
        cout<<"Positive"<<endl;
        return 0;
    }
    if((b-a)%2){
        cout<<"Positive"<<endl;
        return 0;
    }else{
        cout<<"Negative"<<endl;
        return 0;
    }
    
    return 0;
}

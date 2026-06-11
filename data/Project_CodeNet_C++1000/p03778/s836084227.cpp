#include<iostream>
using namespace std;
int main(){
    int w,a,b;
    cin>>w>>a>>b;
    bool connected=false;
    if(a>=b&&a<=b+w){
        connected=true;
    }
    if(a+w>=b&&a+w<=b+w){
        connected=true;
    }
    if(b>=a&&b<=a+w){
        connected=true;
    }
    if(b+w>=a&&b+w<=a+w){
        connected=true;
    }
    if(connected){
        cout<<"0";
    }
    else{
        if(b<a){
            int temp=a;
            a=b;
            b=temp;
            
        }
        cout<<b-w-a;
    }
}
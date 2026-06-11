#include<iostream>
using namespace std;
int main(){
int W,a,b;
    cin>>W>>a>>b;
    if(a+W<=b){
        cout<<b-(a+W)<<endl;
    }
    else if(b+W<=a){
        cout<<a-(b+W)<<endl;
    }
    else if(a<=b && b+W<=a+W){
        if(a+W-b<=b+W-a){
            cout<<0<<endl;
        }
        else
            cout<<0<<endl;
    }
    else if(b<=a+W && a+W<=b+W){
        cout<<0<<endl;
    }
    else if(b<=a && a<=b+W){
        cout<<0<<endl;
    }}
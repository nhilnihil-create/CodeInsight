#include <iostream>
using namespace std;

int main(void){
    int n,num2=0,num4=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a%4==0) num4 ++;
        else if(a%2==0) num2 ++;
    }

    if(num4*2+(num4>0)>=n){
        cout<<"Yes"<<endl;
    }else if(num2>1&&num4*2+num2>=n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
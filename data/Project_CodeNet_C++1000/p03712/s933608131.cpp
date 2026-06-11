#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b;
    char c[102][102]={};
    cin>>a>>b;
    for(int y=0;y<a;y++){
        for(int x=0;x<b;x++){
            cin>>c[x+1][y+1];
        }
    }
    
    for(int y=0;y<a+2;y++){
        for(int x=0;x<b+2;x++){
            //cout<<x<<"x"<<y<<"y";
            if(y==0||y>a){
                cout<<"#";
            }else if(x==0||x>b){
                cout<<"#";
            }else{
                cout<<c[x][y];
            }
        }
        cout<<endl;
    }
}


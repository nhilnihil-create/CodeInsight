#include<iostream>
#define INPUTNUM 100
using namespace std;
int main(void){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int a = ty - sy;
    int b = tx - sx;
    for(int i(0);i<a;i++){
        cout<<"U";
    }
    for(int i(0);i<b;i++){
        cout<<"R";
    }
    for(int i(0);i<a;i++){
        cout<<"D";
    }
    for(int i(0);i<b;i++){
        cout<<"L";
    }
    cout<<"L";
    for(int i(0);i<a+1;i++){
        cout<<"U";
    }
    for(int i(0);i<b+1;i++){
        cout<<"R";
    }
    cout<<"D";
    cout<<"R";
    for(int i(0);i<a+1;i++){
        cout<<"D";
    }
    for(int i(0);i<b+1;i++){
        cout<<"L";
    }
    cout<<"U";
    cout<<endl;
    return 0;
}
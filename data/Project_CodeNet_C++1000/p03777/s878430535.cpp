#include<iostream>
using namespace std;
int main(){
    char a,b;
    cin>>a>>b;
    bool reverse=true;
    if(a=='H'){
        reverse=false;
    }
    if(reverse){
        cout<<(b=='H'?'D':'H');
    }
    else{
        cout<<b;
    }
}
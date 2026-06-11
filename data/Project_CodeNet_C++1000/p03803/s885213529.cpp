#include <bits/stdc++.h>
using namespace std;
int main(void){

int a,b;
cin>>a>>b;

if(a==b){
    cout<<"Draw"<<endl;
}

else if(a==1){
    cout<<"Alice"<<endl;
}

else if(b==1){
    cout<<"Bob"<<endl;
}

else if(a>b){
    cout<<"Alice"<<endl;
}

else if(b>a){
    cout<<"Bob"<<endl;
}
}

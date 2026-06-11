#include<bits/stdc++.h>
using namespace std;
int x,y;

int main(){
    cin>>x>>y;
    if(x<y&&x>1){
        cout<<"Bob"<<endl;
    }
    else if(x>y&&y>1){
        cout<<"Alice"<<endl;
    }
    else if(x<y&&x==1){
        cout<<"Alice"<<endl;
    }
    else if(x>y&&y==1){
        cout<<"Bob"<<endl;
    }
    else if(x==y){
        cout<<"Draw"<<endl;
    }
}

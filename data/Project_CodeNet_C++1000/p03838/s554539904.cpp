#include <bits/stdc++.h>
using namespace std;
long long bit[62][2];
signed main(){
    int x , y , a=0;
    cin>>x>>y;
    if(abs(x) == abs(y)){
        if(x != y){
            a++;
        }
    }
    
    else if(abs(x) > abs(y)){
        if(x>0){
            a++;
        } 
        a+=abs(x)-abs(y);
    
        if(y>0){
            a++;
        }
    }
    
    else{
        if(x<0){
            a++;
        }
        a+=abs(y)-abs(x);
        if(y<0){
            a++;
        }
    }
    
    cout<<a<<endl;
    return(0);
}
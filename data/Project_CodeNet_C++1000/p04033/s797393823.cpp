#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    if(a>0){
        cout<<"Positive"<<endl;
    }
    else if(a<=0 && 0<=b){
        cout<<"Zero"<<endl;
    }
    else if((a+b)%2==0){
        cout<<"Negative"<<endl;
    }
    else{
        cout<<"Positive"<<endl;
    }
    return(0);
}
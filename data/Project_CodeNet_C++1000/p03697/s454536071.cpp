#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    if(n+m>9){
        cout<<"error"<<endl;
    }
    else{
        cout<<n+m<<endl;
    }


    return 0;
}
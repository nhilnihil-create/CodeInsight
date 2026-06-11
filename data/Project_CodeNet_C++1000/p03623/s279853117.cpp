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
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(x-a)<abs(x-b)){
        cout<<"A"<<endl;
    }
    else{
        cout<<"B"<<endl;
    }
    return 0;
}
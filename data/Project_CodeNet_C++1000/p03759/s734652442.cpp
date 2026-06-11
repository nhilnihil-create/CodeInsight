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
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}
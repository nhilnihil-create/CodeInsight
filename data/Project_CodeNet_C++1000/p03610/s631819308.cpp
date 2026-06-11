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
    string s,t;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            t+=s[i];
        }
    }
    cout<<t<<endl;
    return 0;
}
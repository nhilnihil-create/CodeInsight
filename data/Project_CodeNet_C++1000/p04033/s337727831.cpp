#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    double a,b;
    cin>>a>>b;

    if(a>0 && b>0){
        cout<<"Positive"<<"\n";
        return 0;
    }
    else if(a*b<=0){
        cout<<"Zero"<<"\n";
        return 0;
    }
    else{
        int n=(b-a)+1;
        if(n%2==0) cout<<"Positive"<<"\n";
        else cout<<"Negative"<<"\n";
        return 0;
    }
}
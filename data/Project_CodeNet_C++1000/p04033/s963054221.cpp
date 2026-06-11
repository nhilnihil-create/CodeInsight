#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long A,B;cin>>A>>B;
    if(A==0||B==0){
        cout<<"Zero"<<endl;
        return 0;
    }
    if(A<=0&&0<=B){
        cout<<"Zero"<<endl;
        return 0;
    }
    if(A>0&&B>0){
        cout<<"Positive"<<endl;
        return 0;
    }
    if((B-A)%2==1){
        cout<<"Positive"<<endl;
        return 0;
    }
    if((B-A)%2==0){
        cout<<"Negative"<<endl;
        return 0;
    }
}
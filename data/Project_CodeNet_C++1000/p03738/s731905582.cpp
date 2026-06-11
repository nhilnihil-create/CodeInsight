#include <bits/stdc++.h>
using namespace std;

int main(void){
    string A,B;cin>>A>>B;
    if(A.size()>B.size()){
        cout<<"GREATER"<<endl;
        return 0;
    }
    if(A.size()<B.size()){
        cout<<"LESS"<<endl;
        return 0;
    }
    for(int i=0;i<A.size();i++){
        if((int)A[i]>(int)B[i]){
             cout<<"GREATER"<<endl;
            return 0;
        }
        if((int)A[i]<(int)B[i]){
            cout<<"LESS"<<endl;
            return 0;
        }
    }
    cout<<"EQUAL"<<endl;
    return 0;
}
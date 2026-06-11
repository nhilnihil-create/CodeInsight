#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;cin>>S;
    vector<int>A(4,0);
    for(int i=0;i<S.size();i++){
        if(S[i]=='N'){
           A[0]++; 
        }
        if(S[i]=='W'){
           A[1]++; 
        }
        if(S[i]=='S'){
           A[2]++; 
        }
        if(S[i]=='E'){
           A[3]++; 
        }
    }
    if((A[0]>0&&A[2]==0)||(A[1]>0&&A[3]==0)||(A[2]>0&&A[0]==0)||(A[3]>0&&A[1]==0)){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
        return 0;
}
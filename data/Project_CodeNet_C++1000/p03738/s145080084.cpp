#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
    string A,B;
    cin>>A>>B;
    if(A.size()<B.size()){
        cout<<"LESS"<<endl;
    }
    else if(B.size()<A.size()){
        cout<<"GREATER"<<endl;
    }
    else{
        if(A==B){
            cout<<"EQUAL"<<endl;
        }
        else{
            bool C;
            rep(i,A.size()){
                if(A[i]==B[i]){
                }
                else{
                    if(A[i]<B[i]){
                        C=false;
                        break;
                    }
                    else{
                        C=true;
                        break;
                    }
                }
            }
            if(C==true){
                cout<<"GREATER"<<endl;
            }
            else{
                cout<<"LESS"<<endl;
            }
        }
    }
}
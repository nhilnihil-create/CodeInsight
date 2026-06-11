#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int main(){
    
    int N;cin>>N;
    vector<char> A(N),B(N);
    vector<long long int> S(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    int i=1;
    if(A[0]==B[0]) S[0]=3;
    else{
        S[0]=6;
        S[1]=6;
        i++;
    }
    for(;i<N;i++){
        if(A[i]==B[i]){
            if(A[i-1]==B[i-1]) S[i]=(S[i-1]*2)%mod;
            else S[i]=S[i-1];
        }else{
            if(A[i-1]==B[i-1]){
                S[i]=(S[i-1]*2)%mod;
                S[i+1]=S[i];
                i++;
            }else{
                S[i]=(S[i-1]*3)%mod;
                S[i+1]=S[i];
                i++;
            }
        }
    }
    cout<<S[N-1]<<endl;
}


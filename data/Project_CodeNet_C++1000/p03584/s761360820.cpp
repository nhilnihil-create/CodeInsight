#include <iostream>
using namespace std;

int main(){
    int N;
    long long K;
    cin >> N >> K;
    long long A[100000],B[100000];
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];

    int t;
    for(t=30;t>=0;t--){
        if(K & (1<<t)) break;
    }
    long long vmax[32];
    for(int i=0;i<=t+1;i++) vmax[i]=0;
    for(int i=0;i<=t+1;i++){
        if(i>0 && (K&(1<<(i-1)))==0) continue;
        for(int j=0;j<N;j++){
            if(((K>>i)|(A[j]>>i))==(K>>i) && (i==0 || (A[j]&(1<<(i-1)))==0)) vmax[i]+=B[j];
        }
    }

    long long max=0;
    for(int i=0;i<=t+1;i++){
        if(max<vmax[i]) max=vmax[i];
    }

    cout << max << endl;

    return 0;
}
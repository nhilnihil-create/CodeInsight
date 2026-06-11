#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int K,N,A[100001],MAX=0,cnt=0,sum=0,B[100],T[100001],Ah[100001],Th[100001],M[100001];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    for(int i=0;i<N;i++)
        cin >> A[i];
    Th[0] = 1;
    M[0] = T[0];
    for(int i=0;i<N;i++)
        M[i] = 0;
     for(int i=0;i<N-1;i++){
        if(T[i] == T[i+1]){
            Th[i+1] = T[i];
        }else{
            M[i+1] = T[i+1];
            Th[i+1] = 1;
        }
    }
    long long int res=1;
    Ah[N-1] = 1;
    if(M[N-1] != 0 && A[N-1] < M[N-1])
        res = 0;
    for(int i=N-1;i>0;i--){
        if(A[i] == A[i-1]){
            Ah[i-1] = A[i];
        }else{
            Ah[i-1] = 1;
        }
        if(M[i-1] != 0 && A[i-1] < M[i-1])
                res = 0;

    }
    
    for(int i=0;i<N;i++){
        res = (res*min(Ah[i],Th[i]))%1000000007;
    }
    if(T[N-1] != A[0])
        res = 0;
    cout << res << endl;
    return 0;
}
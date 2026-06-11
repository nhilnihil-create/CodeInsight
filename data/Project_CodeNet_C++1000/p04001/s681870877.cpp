#include<bits/stdc++.h>
using namespace std;

int main(){
    long long X; 
    cin >> X;
    int N=log10(X)+1;
    int M=pow(2,N-1);
    long long S=0;
    for (int i=0;i<M;i++){
        long long A=X;
        long long SUM=0;
        int L=0;
        int j=i;
        for (int i2=0;i2<N-1;i2++){
            L=L+1;
            if (j%2==1){
                SUM=SUM+A%(long long)pow(10,L);
                A=A/(long long)pow(10,L);
                L=0;
            }
            j=j/2;
        }
        SUM=SUM+A;
        S=S+SUM;
    }
    cout << S << endl;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long X; 
    cin >> X;
    int N=log10(X)+1;
    int M=pow(2,N-1);
    long long S=0;
    for (int i=0;i<M;i++){
        if (i<N){
            S=S+(pow(2,N-4)*pow(5,i)+pow(2,N-i-1)*pow(10,i)-pow(2,N-4))*((long long)(X/pow(10,i))%10);
        }
    }
    cout << S << endl;
}

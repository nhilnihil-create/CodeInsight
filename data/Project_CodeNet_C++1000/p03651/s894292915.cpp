#include<iostream>
using namespace std;

long long extGCD(long long a, long long b, long long *px, long long *py){
    if(b == 0){
        *px = 1;
        *py = 0;
        return a;
    }
    long long d = extGCD(b, a%b, py, px);
    *py -= a/b * (*px);
    return d;
}

int main(){
    //input
    long long N,K;
    cin >> N >> K;
    long long A[N], A_MAX=0;
    long long i;
    for(i=0; i<N; i++){
        cin >> A[i];
        A_MAX=max(A_MAX,A[i]);
    }

    //calc
    long long g=A[0];
    long long x, y;
    for(i=1; i<N; i++){
        g=extGCD(g,A[i],&x,&y);
    }

    //output
    if((K<=A_MAX)&&(K%g==0)){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    system("pause");
    return 0;
}
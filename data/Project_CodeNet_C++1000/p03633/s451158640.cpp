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
    long long N;
    cin >> N;
    long long T[N];
    long long i;
    for(i=0; i<N; i++){
        cin >> T[i];
    }

    //calc
    long long x, y;
    long long val=T[0];
    for(i=1; i<N; i++){
        val=val*(T[i]/extGCD(val,T[i],&x,&y));
    }

    //output
    cout << val << endl;
    system("pause");
    return 0;
}
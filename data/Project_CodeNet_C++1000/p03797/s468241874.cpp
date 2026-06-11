#include<bits/stdc++.h>
using namespace std;

int main(){
    long N=0,M=0;
    cin >> N >> M;
    if(2*N>=M){
        cout << M/2 << endl;
    }
    else{
        M -= N*2;
        M /= 4;
        cout << N+M << endl;
    }
    return 0;
}
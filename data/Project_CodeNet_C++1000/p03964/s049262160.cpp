#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int N;
    cin >> N;
    int T[N];
    int A[N];
    for(int i=0; i<N; i++){
        cin >> T[i] >> A[i];
    }

    long long currentT = T[0], currentA = A[0];
    for(int i=1; i<N; i++){
        long long nextT=T[i], nextA=A[i];
        if(nextT < currentT || nextA < currentA){
            long long scale = max(
 currentT/nextT, currentA/nextA);
            nextT = T[i]*scale;
            nextA = A[i]*scale;
            if(nextT < currentT || nextA < currentA){
                scale++;
                nextT = T[i]*scale;
                nextA = A[i]*scale;
            }
        }
        currentT = nextT;
        currentA = nextA;
    }
    cout << (currentT + currentA) << '\n';

}

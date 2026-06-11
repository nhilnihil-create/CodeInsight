#include <iostream>
using namespace std;

long long int N;
long long int A[100007];

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    int stop = 0;
    int continueing = 0;
    int mode = 0; // 0 = わからない -1 = 単調非増加 1 = 単調非減少

    if(N != 1){
        for(int i = 0;i < N-1;i++){

            if( (A[i] > A[i+1] && mode == 1) || (A[i] < A[i+1] && mode == -1) ){
                stop++;
                mode = 0;
                continue;
            }

            if(A[i] > A[i+1]){
                mode = -1;
            }
            if(A[i] < A[i+1]){
                mode = 1;
            }
        }
    }

    cout << (stop + 1) << endl;
}
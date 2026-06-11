#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    int N;
    int K;
    long long A[100010];
    long long B[100010];
    long long CAN[30];


    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }

    CAN[0] = K;
    int count = 1;
    for(int i=0;i<30;i++){
        if((K & 1<<i) == 1<<i){
            CAN[count] = (K - (1<<i)) | ((1<<i) - 1);
            count++;
        }
    }

    long long res = 0;
    long long tmp_sum = 0;
    for(int i=0;i<count;i++){
         for(int ii=0;ii<N;ii++){
            if((CAN[i] | A[ii]) == CAN[i]){
                tmp_sum += B[ii];
                /*cout << CAN[i] << ' ' << A[ii] << ' ' << B[ii] << endl;*/
            }
        }
        res = max(res, tmp_sum);
        tmp_sum = 0;
    }
    /*
    for(int ii=0;ii<N;ii++){
        if(CAN[0] == A[ii]){
            tmp_sum += B[ii];
        }
    }
    */
    res = max(tmp_sum, res);
    cout << res << endl;
    return 0;
}
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,k;
    scanf("%ld %ld", &n, &k);
    vector<vector<int>> vvilessThanK(31,vector<int>(30));
    for(long i = 0;  i < 30; i++){
        long l = k % (1<<i) + 1;
        if(l <= k){
            l = k - l;
        }
        else{
            l = 0;
        }
//        printf("%ld\n", l);
        for(int j = 0; j < 30; j++){
            vvilessThanK[i][j] = (l>>j)&1;
        }
    }
    for(int j = 0; j < 30; j++){
        vvilessThanK[30][j] = (k>>j)&1;
    }
    vector<vector<int>> vviNum(n,vector<int>(30));
    vector<long> viValue(n);
    for(long i = 0; i < n; i++){
        long a;
        scanf("%ld %ld", &a, &viValue[i]);
        for(int j = 0; j < 30; j++){
            vviNum[i][j] = (a>>j)&1;
        }
    }
    
    long nAns = 0;
    for(long i = 0; i < 31; i++){
        long iSum = 0;
        for(long j = 0; j < n; j++){
            bool iPlus = true;
            for(long k = 0; k < 30; k++){
                if(vvilessThanK[i][k] == 0 && vviNum[j][k] == 1){
                    iPlus = false;
                    break;
                }
            }
            if(iPlus){
            iSum += viValue[j];
            }
        }
        nAns = (std::max)(iSum, nAns);        
    }
  
    printf("%ld", nAns);
    
    return 0;
}

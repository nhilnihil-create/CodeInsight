#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int D[K];
    for(int i = 0; i < K; ++i){
        scanf("%d", D + i);
    }
    int n_ok = 10 - K;
    vector<int> ok_to_use;
    for(int i = 0; i < 10; ++i){
        if(!binary_search(D, D + K, i)) ok_to_use.push_back(i);
    }
    int tmp;
    for(int i = 0; i < n_ok; ++i){
        if(ok_to_use[i] >= N){
            printf("%d\n", ok_to_use[i]);
            return 0;
        }
    }
    for(int j = 0; j < n_ok; ++j){
        for(int i = 0; i < n_ok; ++i){
            tmp = 10*ok_to_use[j] + ok_to_use[i];
            if(tmp >= N){
                printf("%d\n", tmp);
                return 0;
            }
        }
    }
    for(int k = 0; k < n_ok; ++k){
        for(int j = 0; j < n_ok; ++j){
            for(int i = 0; i < n_ok; ++i){
                tmp = 100*ok_to_use[k] + 10*ok_to_use[j] + ok_to_use[i];
                if(tmp >= N){
                    printf("%d\n", tmp);
                    return 0;
                }
            }
        }
    }
    for(int l = 0; l < n_ok; ++l){
        for(int k = 0; k < n_ok; ++k){
            for(int j = 0; j < n_ok; ++j){
                for(int i = 0; i < n_ok; ++i){
                    tmp = 1000*ok_to_use[l] + 100*ok_to_use[k] + 10*ok_to_use[j] + ok_to_use[i];
                    if(tmp >= N){
                        printf("%d\n", tmp);
                        return 0;
                    }
                }
            }
        }
    }
    for(int m = 0; m < n_ok; ++m){
        for(int l = 0; l < n_ok; ++l){
            for(int k = 0; k < n_ok; ++k){
                for(int j = 0; j < n_ok; ++j){
                    for(int i = 0; i < n_ok; ++i){
                        tmp = 10000*ok_to_use[m] + 1000*ok_to_use[l] + 100*ok_to_use[k] + 10*ok_to_use[j] + ok_to_use[i];
                        if(tmp >= N){
                            printf("%d\n", tmp);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
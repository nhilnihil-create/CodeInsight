#include<iostream>
using namespace std;

int main(){
    //input
    int N, K;
    cin >> N >> K;
    long long a[N+1];
    int i, j;
    for(i = 1; i <= N; i++){
        cin >> a[i];
    }

    //calc
    long long costmin = 100000000000, cost;
    int reform;
    long long heightmax[N+1], heightmaxcopy[N+1], height_after_reform;
    heightmax[1] = a[1];
    for(i = 2; i <= N; i++){
        heightmax[i] = max(a[i],heightmax[i-1]);
    }
    int bit;
    for(bit = 0; bit < (1<<(N-1)); bit++){
        cost = 0;
        reform = 0;
        for(i = 0; i < N-1; i++){
            reform += ((bit>>i) & 1);
        }
        if(reform != K-1) continue;
        for(i = 1; i <= N; i++){
            heightmaxcopy[i] = heightmax[i];
        }
        for(i = 2; i <= N; i++){
            if(!((bit>>(i-2)) & 1)) continue;
            height_after_reform = max(heightmaxcopy[i-1]+1,a[i]);
            cost += height_after_reform - a[i];
            heightmaxcopy[i] = height_after_reform;
            for(j = i+1; j <= N; j++){
                heightmaxcopy[j] = max(a[j],heightmaxcopy[j-1]);
            }
        }
        if(costmin > cost){
            costmin = cost;
        }
    }
    if(costmin == 100000000000){
        costmin = 0;
    }

    //answer
    cout << costmin << endl;
    system("pause");
    return 0;
}
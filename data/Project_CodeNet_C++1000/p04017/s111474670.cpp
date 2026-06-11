#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> x(N);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    int L;
    cin >> L;
    int Q;
    cin >> Q;
    vector<pair<int, int>> ab(Q);
    int a, b;
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        ab[i] = make_pair(a - 1, b - 1);
    }

    vector<int> parentAB(N);
    int tempIndex = 0;
    int stopIndex = 1;
    while(stopIndex <= N - 2){
        if(x[tempIndex] + L >= x[stopIndex + 1]){
            stopIndex++;
        }
        else{
            parentAB[tempIndex] = stopIndex;
            tempIndex++;
        }
    }
    while(tempIndex <= N - 2){
        parentAB[tempIndex] = N - 1;
        tempIndex++;
    }
    parentAB[N - 1] = N;
    vector<vector<int>> doublingAB(18, vector<int>(N));
    for(int i = 0; i < N; i++){
        doublingAB[0][i] = parentAB[i];
    }
    for(int i = 1; i < 18; i++){
        for(int j = 0; j < N; j++){
            int p = doublingAB[i - 1][j];
            if(p == N){
                doublingAB[i][j] = N;
            }
            else{
                doublingAB[i][j] = doublingAB[i - 1][p];
            }
        }
    }

    vector<int> parentBA(N);
    tempIndex = N - 1;
    stopIndex = N - 2;
    while(stopIndex >= 1){
        if(x[tempIndex] - L <= x[stopIndex - 1]){
            stopIndex--;
        }
        else{
            parentBA[tempIndex] = stopIndex;
            tempIndex--;
        }
    }
    while(tempIndex >= 1){
        parentBA[tempIndex] = 0;
        tempIndex--;
    }
    parentBA[0] = -1;
    vector<vector<int>> doublingBA(18, vector<int>(N));
    for(int i = 0; i < N; i++){
        doublingBA[0][i] = parentBA[i];
    }
    for(int i = 1; i < 18; i++){
        for(int j = 0; j < N; j++){
            int p = doublingBA[i - 1][j];
            if(p == -1){
                doublingBA[i][j] = -1;
            }
            else{
                doublingBA[i][j] = doublingBA[i - 1][p];
            }
        }
    }

    for(int i = 0; i < Q; i++){
        auto temp = ab[i];
        a = temp.first;
        b = temp.second;
        if(a < b){
            int tempPosIndex = a;
            int step = 0;
            int ans = N;
            for(int j = 17; j >= 0; j--){
                int tempIndex = doublingAB[j][tempPosIndex];
                if(tempIndex >= b){
                    ans = min(ans, step + (1 << j));
                }
                else{
                    tempPosIndex = tempIndex;
                    step += (1 << j);
                }
            }
            cout << ans << endl;
        }
        else{   // a > b
            int tempPosIndex = a;
            int step = 0;
            int ans = N;
            for(int j = 17; j >= 0; j--){
                int tempIndex = doublingBA[j][tempPosIndex];
                if(tempIndex <= b){
                    ans = min(ans, step + (1 << j));
                }
                else{
                    tempPosIndex = tempIndex;
                    step += (1 << j);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin>> N >> M;


    vector<vector<int>> x(N+1);

    for(int i=0; i<M; i++){
        int a, b;
        cin>> a >> b;
        x[a].push_back(b);
    }

    for(auto a : x[1]){
        for(auto b : x[a]){
            if(b == N){
                cout<< "POSSIBLE" <<endl;
                return 0;
            }
        }
    }
    cout<< "IMPOSSIBLE" <<endl;
    return 0;
}
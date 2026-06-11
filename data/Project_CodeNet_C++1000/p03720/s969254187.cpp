#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    int aM[M];
    int bM[M];
    for(int i = 0 ; i < M ; i++){
        cin >> aM[i] >> bM[i];
    }
    
    vector<int> counter(N+1);
    for(int i = 1 ; i <= N ; i++){
        counter[i] = 0;
        for(int j = 0 ; j < M ; j++){
            if( i == aM[j] || i == bM[j] ) counter[i]++;
            
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        cout << counter[i] << endl;
    }
    return 0;
}
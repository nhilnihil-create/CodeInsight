#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool judge(int N, int M, int K){
    for(int line = 0; line <= M; line++){
        int black = N * line;
        int diff = M - 2*line;
        for(int i = 0; i <= N; i++){
            int result = black + diff * i;
            if(result == K){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    if(judge(N, M, K) || judge(M, N, K)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

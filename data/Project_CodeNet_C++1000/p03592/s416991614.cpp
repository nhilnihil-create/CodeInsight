#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool solve(int N, int M, int K){
    for(int n=0; n<=N; n++){
        int cnt = n*M;
        int delta = N - 2*n;
        for(int m=0; m<=M; m++){
            if(cnt + delta*m == K){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int N, M, K;  cin >> N >> M >> K;
    if(solve(N, M, K)){
        cout << "Yes" << endl;
    }else if(solve(M, N, K)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}   
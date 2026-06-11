#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll N, M;
    cin >> N >> M;
    char A[50][50];
    char B[50][50];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> B[i][j];
        }
    }
    ll cnt = 0;
    bool flag = false;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                for(int l = 0; l < M; l++){
                    if(A[i + k][j + l] == B[k][l]){
                        cnt++;
                        if(cnt == M * M){
                            flag = true;
                        }
                    }
                    else{
                        cnt = 0;
                    }                    
                }
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

#include <iostream>

using namespace std;

long A[300][300];
long d[300][300];

void WarshallFloyd(int size){
    //init
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < size; j++){
            d[i][j] = A[i][j];
        }
    }
    for(int k = 0; k < size; k++){
        for(int i = 0; i < size ; i++){
            for(int j = 0; j < size; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    bool same = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N;j++){
            cin >> A[i][j];
        }
    }
    WarshallFloyd(N);
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            if(d[i][j] != A[i][j]){
                same = false;
            }
        }
    }
    if(same){
        long ans = 0;
        bool deleted[300][300];
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < N; j++){
                ans += A[i][j];
                deleted[i][j] = false;
            }
        }
        
        for(int k = 0; k < N ; k++){
            for(int i = 0; i < N ; i++){
                for(int j = 0; j < N; j++){
                    if(A[i][j] == A[i][k]+ A[k][j] && deleted[i][j] == false && i!= k && j!=k){
                        ans -= A[i][j];
                        deleted[i][j] = true;
                    }
                }
            }
        }
        cout << ans/2 << endl;
    }else{
        cout << -1 << endl;
    }
}
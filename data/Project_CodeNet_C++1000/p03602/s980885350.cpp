#include<iostream>
using namespace std;

typedef long long ll;
int MAX_NODE = 300;

int main()
{
    // 整数の入力
    int N;
    cin >> N;
    int A[MAX_NODE][MAX_NODE];
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }

    ll total = 0;
    bool isValid = true;
    for (int i =0;i<N; i++){
        for (int j = i + 1;j<N;j++){
            bool needed = true;
            for (int k = 0; k<N;k++){
                if (k != i && k!=j){
                    if (A[i][j] > A[i][k] + A[k][j]){
                        isValid = false;
                    }
                    else if (A[i][j] == A[i][k] + A[k][j]){
                        needed = false;
                    }
                }
            }
            if (needed){
                total += A[i][j];
            }

        }

    }

    if (isValid){
        cout<<total<<endl;
    } else {
        cout<<-1<<endl;
    }
    return 0;
}
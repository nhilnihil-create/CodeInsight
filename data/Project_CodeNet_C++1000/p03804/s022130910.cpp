#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int N ,M;
    cin >> N >> M;
    char A[50][50], B[50][50];
    rep(i, N){
        rep(j, N){
            cin >> A[i][j];
        }
    }
    rep(i, M){
        rep(j, M){
            cin >> B[i][j];
        }
    }
    bool exist = false;
    rep(i, N-M+1){
        rep(j, N-M+1){
            bool match = true;
            rep(k, M){
                rep(l, M){
                    if(A[k+i][l+j]!=B[k][l]) match = false;
                }
            }
            if(match) exist =true;
        }
    }
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
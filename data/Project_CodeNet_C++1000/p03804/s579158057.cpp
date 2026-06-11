#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int N,M;
vector<vector<char> > A,B;

bool Matching(int i, int j){
    rep(k,0,M){
        rep(l,0,M){
            int x = i+k;
            int y = j+l;
            if(A[x][y] != B[k][l]){
                return false;
            } 
        }
    }
    return true;
}

int main(){
    cin >> N >> M;
    A.resize(N+1,vector<char>(N+1));
    B.resize(M+1,vector<char>(M+1));
    rep(i,0,N){
        rep(j,0,N){
            cin >> A[i][j];
        }
    }
    rep(i,0,M){
        rep(j,0,M){
            cin >> B[i][j];
        }
    }

    bool ok = false;
    rep(i,0,N-M+1){
        rep(j,0,N-M+1){
            if(Matching(i,j)) ok = true;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 77;
char A[N][N] , B[N][N];
void sol(){
    int n , m ; cin >> n >> m ;
    for(int i = 0 ; i < n ; ++i) for(int j = 0 ; j < n ; ++j) cin >> A[i][j];
    for(int i = 0 ; i < m ; ++i) for(int j = 0 ; j < m ; ++j) cin >> B[i][j];
    for(int i = 0 ; i < n-m+1; ++i){
        for(int j = 0 ; j < n-m+1 ; ++j){
            int c = 0;
            for(int a = 0 ;a < m ; ++a){
                for(int b = 0 ; b < m ; ++b){
                    // cout << A[i+a][j+b];
                    if(B[a][b]==A[i+a][j+b]) c++;
                }
                // cout << endl;
            }
            if(c==m*m){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int32_t main(){
    fast;
    int t =1; 
    // cin >> t; 
    while(t--) sol();    
    return 0;
}
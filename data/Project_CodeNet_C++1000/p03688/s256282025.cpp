#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N; cin >> N;
    int A[N]; rep(i, N) cin >> A[i];
    sort(A, A+N);
    if(A[N-1]-A[0] >= 2){
        cout << "No" << endl;
    }
    else if(A[N-1]-A[0] == 1){
        // 2 2 3 3 3はあり得るか? -> ある a b c c c

        // a a a ... a a+1 a+1 a+1 ... a+1
        // a+1同士は同じ色でないといけないか?そんなことはないはず
        // aとa+1は同じ色だとまずいか?
        // aとa+1から見ると,お互い以外は見ているものが同じなのに見える色の種類が1違う
        // a+1側から見るとaは他のどれとも違う色で,a側から見るとa+1は他のどれかと同じ色でなくてはいけない
        // すると、aは互いに異なる色である必要があることがわかる
        // aの個数をkとすると、k <= a+1
        // 残りのa+1-k種類をa+1で頑張る
        // a+1-k=0 -> 
        // 2 2 2 3は? -> むり
        // 3 3 3 3 4は?
        int k = 1;
        int i = 0;
        while(A[i] == A[i+1]){k++; i++;}
        if(k <= A[N-1]){
            int rem = A[N-1]-k;
            if(rem == 0) cout << "No" << endl;
            else if((N-k)/rem >= 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if(N/A[0] >= 2 || A[0] == N-1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
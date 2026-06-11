#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

int main(void){
    int N, x; cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;
    }
    else if(x == 2 || x == 2*N-2){
        if(N == 2){
            cout << "Yes" << endl;
            rep(i, 3) cout << i+1 << endl;
        }
        else if(N == 3){
            cout << "Yes" << endl;
            if(x == 2) printf("4\n1\n2\n3\n5\n");
            else printf("1\n5\n4\n2\n3\n");
        }
        else{
            cout << "Yes" << endl;
            vector<int> out_order(2*N, 0);
            for(int i = 1; i < out_order.size(); i++){
                out_order[i] = i;
            }
            if(x == 2){
                swap(out_order[N-1], out_order[1]);
                swap(out_order[N], out_order[2]);
            }
            else{
                swap(out_order[N+1], out_order[2*N-1]);
                swap(out_order[N], out_order[2*N-2]);
            }
            for(int i = 1; i < out_order.size(); i++) cout << out_order[i] << endl;

        }

    }
    else{
        //N > 3で構築可能。真ん中にxxxとなるようにする
        //A = (a_1, a_2,  ..., a_n-2, a_n-1, a_n, a_n+1, a_n+2, ..., a_2n-1)とすると
        //a_n-2 = x-2, a_n-1 = x+1, a_n = x, a_n+1 = x-1, a_n+2 = x+2とする
        cout << "Yes" << endl;

        int use[2*N] = {};
        use[x-2] = 1; use[x-1] = 1; use[x] = 1; use[x+1] = 1; use[x+2] = 1;
        int out_order[2*N] = {};
        out_order[N-2] = x-2; out_order[N-1] = x+1; out_order[N] = x; out_order[N+1] = x-1; out_order[N+2] = x+2;
        int loop = 2*N;
        int idx_use = 1;
        for(int i = 1; i < loop; i++){
            if(out_order[i] != 0) continue;
            while(use[idx_use] == 1) idx_use++;
            out_order[i] = idx_use;
            use[idx_use] = 1;
        }
        for(int i = 1; i < loop; i++){
            cout << out_order[i] << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int r[30][100000];

int calc(int v, int d){
    if(d == 0) return v;
    int n = 1;
    for(int i = 0; i < 30; i++){
        if(n&d){
            if(d-n == 0) return r[i][v];
            else return calc(r[i][v], d-n); 
        }
        n = (n<<1);
    }
}

int main(){
    int N;
    int x[100000];
    int L;
    int Q;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> x[i];
    cin >> L;
    for(int i = 0; i < N-1; i++){
        int *p = upper_bound(x, x+N, x[i]+L);
        r[0][i] = p-x-1;
    }
    r[0][N-1] = N-1;
    for(int i = 1; i < 30; i++){
        r[i][N-1] = N-1;
        for(int j = 0; j < N-1; j++){
            r[i][j] = r[i-1][r[i-1][j]];
            //cout << r[i][j] << ' ';
        }
        //cout << endl;
    }

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        int l = 0;
        int r = N;
        while(r-l > 1){
            int c = (l+r)/2;
            if(calc(a, c) >= b) r = c;
            else l = c;
        }
        cout << r << endl;
    }
}
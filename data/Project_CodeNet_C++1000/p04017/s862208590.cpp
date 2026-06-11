#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, l;
vector<int> x;
vector< vector<int> > dbl;
/*
int f(int a, int b, int res){
    if(a > b) return f(b, a, 0);
    if(a == b) return res;
    for(int k = 20-1; k >= 0; k--){
        if(dbl[a][k] >= b){
            return f(dbl[a][k-1], b, res + (1<<k));
        }
    }
    return 1e9;
}*/

int f(int a, int b){
    if(a > b) return f(b, a);
    int res = 0;
    while(a < b){
        for(int k = 0; k < 20; k++){
            if(dbl[a][k] >= b){
                if(k == 0){
                    a = b;
                    res++;
                }else{
                    a = dbl[a][k-1];
                    res += (1 << (k-1));
                }
                break;
            }
        }
    }
    return res;
}

int main(void){
    cin >> n;
    x.assign(n, 0);
    for(int i=0;i<n;i++) cin >> x[i];
    cin >> l;
    dbl.assign(n, vector<int>(20, 0));

    int nx = 0;
    for(int i=0;i<n;i++){
        while(nx+1 < n && x[nx+1] <= x[i]+l) nx++;
        dbl[i][0] = nx;
    }
    for(int k=1;k<20;k++){
        for(int i=0;i<n;i++){
            dbl[i][k] = dbl[dbl[i][k-1]][k-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << f(--a, --b) << endl;
    }
}

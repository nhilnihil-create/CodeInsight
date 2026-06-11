#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int nxt[20][100000], rev[20][100000];

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++)  cin >> x[i];
    vector<int> y(n);
    for(int i = 0; i < n; i++)  y[i] = 1e9-x[n-1-i];
    int l;
    cin >> l;
    for(int i = 0; i+1 < n; i++){
        nxt[0][i] = upper_bound(x.begin(),x.end(),x[i]+l)-x.begin()-1;
        rev[0][i] = upper_bound(y.begin(),y.end(),y[i]+l)-y.begin()-1;
    }
    nxt[0][n-1] = -1;
    rev[0][n-1] = -1;
    for(int k = 0; k+1 < 20; k++){
        for(int i = 0; i < n; i++){
            if(nxt[k][i] < 0)  nxt[k+1][i] = -1;
            else               nxt[k+1][i] = nxt[k][nxt[k][i]];
            if(rev[k][i] < 0)  rev[k+1][i] = -1;
            else               rev[k+1][i] = rev[k][rev[k][i]];
        }
    }
    auto f = [&](int a, int b, int c[20][100000])->int{
        int ret = 0, tmp = a;
        for(int k = 19; k >= 0; k--){
            int to = c[k][tmp];
            if(to >= 0 && to < b){
                tmp = to;
                ret += 1<<k;
            }
        }
        return ret+1;
    };
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a < b)   cout << f(a, b, nxt) << endl;
        else        cout << f(n-1-a, n-1-b, rev) << endl;
    }
    return 0;
}
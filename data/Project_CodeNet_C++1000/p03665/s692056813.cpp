#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

void comb(vector<vector <long long int> > &v){
        for(int i = 0;i <v.size(); i++){
                v[i][0]=1;
                v[i][i]=1;
        }
        for(int k = 1;k <v.size();k++){
                for(int j = 1;j<k;j++){
                        v[k][j]=(v[k-1][j-1]+v[k-1][j]);
                }
        }
}

int main(void){
        int N, P;
        cin >> N >> P;
        int a[2] = {0,0};
        rep(i,N) {
                int A;
                cin >> A;
                a[A%2]++;
        }

        ll ans = 1;
        rep(i, a[0]) ans *= 2;
        ll tmp = 0;
        vector<vector<ll>> v(a[1]+1, vector<ll>(a[1]+1,0));
        comb(v);
        if (P == 0) {
                for (int i = 0; i <= a[1]; i+=2) tmp += v[a[1]][i];
        }
        else {
                for (int i = 1; i <= a[1]; i+=2) tmp += v[a[1]][i];
        }
        ans *= tmp;
        cout << ans << endl;
        return 0;
}
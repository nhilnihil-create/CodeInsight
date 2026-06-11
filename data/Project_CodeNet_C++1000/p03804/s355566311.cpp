#include <bits/stdc++.h>
#define pii pair<int, int>;
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 1 << 31;


int main(){

    ios_base::sync_with_stdio(false);
    int n, m;
    string a[51], b[51];

    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    int count = 0, maior = 0;
    for (int i=0; i<= n-m; i++){
        for (int j=0; j<=n-m; j++){
            count = 0;
            for (int k =0; k<m; k++){
                for (int l=0; l<m; l++){
                    if (a[i+k][j+l] == b[k][l]) count++;
                }
            }
            maior = max(maior, count);
        }
    }

    cout << (maior == m*m? "Yes" : "No") << endl;
    return 0;
}
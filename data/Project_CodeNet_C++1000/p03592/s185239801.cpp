#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i*(m-j) + j*(n-i) == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    system("pause");
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll imos[100010];
ll sum = 0;
ll A[100010];
int n, m;

void add_range(int l, int r, int x){
    imos[l] += x;
    imos[r + 1] -= x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 1; i < n; i++){
        if(A[i - 1] < A[i]){
            sum += A[i] - A[i - 1];
            add_range(A[i - 1] + 2, A[i], 1);
            add_range(A[i] + 1, A[i] + 1, - A[i] + A[i - 1] + 1);
        }else{
            sum += m - A[i - 1] + A[i];
            add_range(A[i - 1] + 2, m, 1);
            add_range(1, 1, m - A[i - 1]);
            add_range(2, A[i], 1);
            add_range(A[i] + 1, A[i] + 1, - m + A[i - 1] - A[i] + 1);
        }
    }
    ll mx = 0;
    ll s = 0;
    for(int i = 1; i <= m; i++){
        s += imos[i];
        imos[i + 1] += imos[i];
        chmax(mx, s);
    }
    cout << sum - mx << endl;
    return 0;
}
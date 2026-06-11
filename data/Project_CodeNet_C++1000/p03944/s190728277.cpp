#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> X(N);
    vector<int> Y(N);
    vector<int> A(N);
    ll ans = 0;
    vector<vector<char>> B(H, vector<char>(W, '-'));
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i] >> A[i];
        if(A[i] == 1){
            for (int j = 0; j < H;j++)
            {
                for (int k = 0; k < X[i];k++)
                {
                    B[j][k] = '*';
                }
            }
        }
        else if(A[i] == 2){
            for (int j = 0; j < H;j++)
            {
                for (int k = X[i]; k < W;k++)
                {
                    B[j][k] = '*';
                }
            }
        }
        else if(A[i] == 4){
            for (int j = Y[i]; j < H;j++)
            {
                for (int k = 0; k < W;k++)
                {
                    B[j][k] = '*';
                }
            }
        }
        else{
            for (int j = 0; j < Y[i];j++)
            {
                for (int k = 0; k < W;k++)
                {
                    B[j][k] = '*';
                }
            }
        }
    }
    for (int i = 0; i < H;i++)
    {
        for (int j = 0; j < W;j++)
        {
            if(B[i][j] == '-'){
                ans++;
            }
            //cout << B[i][j];
        }
        //cout << endl;
    }
    cout << ans << endl;
}

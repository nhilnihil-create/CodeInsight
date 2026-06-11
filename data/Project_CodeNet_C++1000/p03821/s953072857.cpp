#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
 
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll lcm(ll a,ll b){
    return (a * b) / __gcd(a,b);
}

const ll INF = 10010001010;
const int inf = 1000034000;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    ll count = 0;

    for(int i = 0;i < N;i++){
        cin >> A[i] >> B[i];
    }
    for(int i = N-1;i >= 0;i--){
        ll X = count + A[i];
        if(X % B[i] != 0){
            count += B[i] - X % B[i];
        }
    }
    cout << count << endl;
}
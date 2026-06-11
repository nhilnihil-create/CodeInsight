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
    deque<int> B;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        if(i%2 == 1){
            B.push_back(A[i]);
        }
        else{
            B.push_front(A[i]);
        }
    }
    if(N %2 == 0){
        for(int i = B.size()-1;i >= 0;i--){
            cout << B[i] <<" ";
        }
    }
    else{
        for(int i = 0;i < B.size();i++){
            cout << B[i] <<" ";
        }
    }
    cout << endl;
} // 7 7 0 6 6 0
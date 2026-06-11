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
const ll INF = 10010001010;
const int inf = 1000034000;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main() {
    ll N;
    cin >> N;
    vector<int> A(N);
    int count = 1;
    int now = 0;
    for(int i = 0;i < N;i++){
            cin >> A[i];
    }
    bool inc = false;
    int D = 0;
    for(int i = 0;i < N-1;i++){
        if(D == 1){
            if(A[i] > A[i+1]){
                count++;
                D = 0;
            }
        }
        else if(D == -1){
            if(A[i] < A[i+1]){
                count++;
                D = 0;
            }
        }
        else{
            if(A[i] > A[i+1]){
                D= -1;
            }
            else if(A[i] < A[i+1]){
                D = 1;
            }
            else{
                D = 0;
            }
        }
    }
    cout<< count << endl;
} 
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
ll INF = 10010001010;

ll lcm(ll a,ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    string A;
    cin >> A;
    int N = A.size();
    int n, S, W, E;
    n = S = W = E = 0;
    for (int i = 0; i < N; i++)
    {
        if(A[i] == 'N'){
            n++;
        }
        else if(A[i] == 'S'){
            S++;
        }
        else if(A[i] == 'W'){
            W++;
        }
        else
        {
            E++;
        }
    }
    if(n != 0){
        if(S == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    if(S != 0){
        if(n == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    if (W != 0)
    {
        if (E == 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (E != 0)
    {
        if (W == 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair < int , int >;
constexpr int INF = (1 << 30) - 1; 
int N, K;
vector < int > G[2005];

int calcDelete(int prev, int node, int depth) {
    int ret = (depth > (K + 1) / 2);
    for ( auto &to : G[node] ) if ( to != prev ) ret += calcDelete(node, to, depth + 1);
    return ( ret );
}

int main()
{
    int A[2005], B[2005];
    cin >> N >> K;
    for ( int i = 0; i < N - 1; i++ ) {
        cin >> A[i] >> B[i]; --A[i], --B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    int minv = INF;
    if ( K % 2 == 0 ) {
        for ( int root = 0; root < N; root++ ) {
            minv = min(minv, calcDelete(-1, root, 0));
        }
    } else {
        for ( int i = 0; i < N - 1; i++ ) {
            minv = min(minv, calcDelete(B[i], A[i], 1) + calcDelete(A[i], B[i], 1));
        }
    }
    cout << minv << endl;

    return ( 0 );
}

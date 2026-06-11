#include <iostream>
#include <vector>

#define MAX_N 100000
#define MAX_M 100

using namespace std;

int N, M;
int A[MAX_N];

vector<int> solve()
{
    vector<int> B;

    vector<int> idx_odds;
    for ( int i = 0; i < M; i++ )
        if ( A[i] % 2 ) idx_odds.push_back( i );

    switch ( idx_odds.size() )
    {
    case 2:
        swap( A[idx_odds[1]], A[M - 1] );
    case 1:
        swap( A[idx_odds[0]], A[0] );
        break;
    case 0:
        break;
    default:
        return B;
    }

    if ( A[0] > 1 ) B.push_back( A[0] - 1 );
    switch ( M )
    {
    case 1:
        B.push_back( 1 );
        break;
    // case 2:
    //     B.push_back( A[1] + 1 );
    //     break;
    default:
        for ( int i = 1; i < M - 1; i++ ) B.push_back( A[i] );
        B.push_back( A[M - 1] + 1 );
    }

    return B;
}

int main( int argc, char **argv )
{
    cin >> N >> M;

    for ( int i = 0; i < M; i++ ) cin >> A[i];

    auto ans = solve();

    if ( ans.size() == 0 )
        cout << "Impossible" << endl;
    else
    {
        for ( int i = 0; i < M - 1; i++ ) cout << A[i] << " ";
        cout << A[M - 1] << endl;

        cout << ans.size() << endl;

        for ( int i = 0; i < ans.size() - 1; i++ ) cout << ans[i] << " ";
        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
}

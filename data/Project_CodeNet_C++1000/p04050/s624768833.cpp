#include <iostream>
#include <iterator>
#include <vector>

#define MAX_M 100

using namespace std;

int N, M;
int A[MAX_M];

vector<int> solve()
{
    vector<int> B;

    vector<int> O; // 奇数のインデックス
    for ( int i = 0; i < M; i++ )
        if ( A[i] % 2 ) O.push_back( i );

    switch ( O.size() )
    {
    case 2:
        swap( A[O[1]], A[M - 1] );
    case 1:
        swap( A[O[0]], A[0] );
        break;
    case 0:
        break;
    default:
        return B;
    }

    if ( A[0] > 1 ) B.push_back( A[0] - 1 );

    for ( int i = 1; i < M - 1; i++ ) B.push_back( A[i] );

    B.push_back( M == 1 ? 1 : A[M - 1] + 1 );

    return B;
}

int main( int argc, char **argv )
{
    cin >> N >> M;

    for ( int i = 0; i < M; i++ ) cin >> A[i];

    auto B = solve();

    if ( B.size() == 0 )
        cout << "Impossible" << endl;
    else
    {
        copy( A, A + M, ostream_iterator<int>( cout, " " ) );
        cout << endl;

        cout << B.size() << endl;

        copy( B.begin(), B.end(), ostream_iterator<int>( cout, " " ) );
        cout << endl;
    }

    return 0;
}

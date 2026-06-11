#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> vc( N * M );
    for( auto &x : vc )
    {
        cin >> x;
    }
    vector<string> W{"A","B","C","D","E","F","G","H","I","J","K","L","M","N",
                     "O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    REP( i, N * M )
    {
        if( vc[ i ] == "snuke" )
        {
            cout << W[ i % M ] << i / M + 1 << endl;
        }
    }
    return 0;
}
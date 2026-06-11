#include <iostream>

using namespace std;

string s[30][30];

int n,m,i,j,x,y ;

int main()
{
    ios_base :: sync_with_stdio(false) ;

    cin >> n >> m ;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; ++j)
            cin >> s[i][j] ;
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            if(s[i][j] == "snuke")
                cout << (char)('A'+j) << i+1;
    }

    return 0;
}

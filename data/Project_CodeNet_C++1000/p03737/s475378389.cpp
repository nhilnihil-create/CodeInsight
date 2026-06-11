#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    
    char ans[3] = {s1[0] - 0x20,s2[0] - 0x20,s3[0] - 0x20};
    
    cout << ans << endl;
}

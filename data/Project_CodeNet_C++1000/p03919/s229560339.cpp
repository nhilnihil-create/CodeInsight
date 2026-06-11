#include <cstdio>
#include <iostream>
#define MOD 1000000007
#define INT long long
using namespace std;
int a, b, X, Y;
string s[30][30];
int main()
{
    cin>>a>>b;
    for(int i = 0 ; i < a ; i++ ) for(int j = 0 ; j < b ; j++ ) cin>>s[i][j];
    for(int i = 0 ; i < a ; i++ ) for(int j = 0 ; j < b ; j++ )
        if( s[i][j] == "snuke" ) X = i+1, Y = j;
    printf("%c%d\n", Y+'A', X);
    return 0;
}
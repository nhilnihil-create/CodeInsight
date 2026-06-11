#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define rforn(a, n) for(int a = (n)-1; a>=0; --a)
using namespace std;
const int N = 6e5+20;

int main()
{
    int n, m, p;
    cin>>n>>m>>p;
    
    if( max(n, max(m, p)) == 7)
    {
        if( min(n, min(m, p)) == 5 && n+m+p == 5 + max(n, max(m, p)) + min(n, min(m, p)) ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
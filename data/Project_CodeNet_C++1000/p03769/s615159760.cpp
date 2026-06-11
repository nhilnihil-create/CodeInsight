#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long int64;
int64 n;
vector<int> meth[2];
int m;
int main()
{
    scanf("%lld", &n), ++n;
    for(int i = 1; n > 1; ++i) meth[n&1].push_back(i), n = n&1?(n-1):(n>>1);
    m = meth[0].size()+meth[1].size(); printf("%d\n", m<<1);    
    for(int i = 0; i < meth[1].size(); ++i) printf("%d ", meth[1][i]);
    for(int i = meth[0].size()-1; ~i; --i) printf("%d ", meth[0][i]);
    for(int i = m; i; --i) printf("%d ", i);
    return 0;
}
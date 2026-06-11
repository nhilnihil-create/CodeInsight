#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 2e4+5;
int n, d = 4e4, b[N];
int main()
{
    n = (N-5)*d;
    n = read(); 
    for(int i = 1; i <= n; ++i) b[read()] += i, b[i] += (n-i+1)*d, printf("%d ", i*d); puts("");
    for(int i = 1; i <= n; ++i) printf("%d ", b[i]); 
    return 0;
}
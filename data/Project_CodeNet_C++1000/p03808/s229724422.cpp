#include <cctype>
#include <algorithm>
#include <cstdio>
typedef long long int64;
using namespace std;
inline int read(int f = 1, int x = 0, char ch = '-')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x; 
}
const int N = 1e5+5;
int s[N], d[N];
int64 n, m;
int main()
{
    n = read();
    for(int i = n; i; --i) s[i] = read(), m += s[i];
    if(m%(n*(n+1)/2)) return puts("NO"), 0;
    m /= n*(n+1)/2; 
    for(int i = n-1; i; --i) d[i] = s[i+1]-s[i]; d[n] = s[1]-s[n];
    for(int i = n; i; --i) if((m+d[i])%n||m+d[i] < 0) return puts("NO"), 0;
    puts("YES");
    return 0;
}
/*
2
99998 1
*/
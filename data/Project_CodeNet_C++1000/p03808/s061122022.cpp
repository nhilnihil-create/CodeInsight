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
int n, m, s[N];
int64 t;
int main()
{
    n = read();
    for(int i = n; i; --i) s[i] = read(), t += s[i]; s[n+1] = s[1];
    if(t%(n*(n+1ll)/2)) return puts("NO"), 0;
    m = t/(n*(n+1ll)/2); 
    for(int i = n; i; --i) if((m+s[i+1]-s[i])%n||m+s[i+1]-s[i] < 0) return puts("NO"), 0;
    puts("YES");
    return 0;
}
/*
2
99998 1
*/
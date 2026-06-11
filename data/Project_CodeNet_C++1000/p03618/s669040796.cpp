#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int N = 2e5+5;
char s[N];
int n, f[26][N];
int64 ans;
int main()
{
    scanf("%s", s+1), n = strlen(s+1);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 26; ++j)
            f[j][i] = f[j][i-1]+(s[i] == j+'a');
    for(int i = 1; i <= n; ++i) ans += (n-i+1)-(f[s[i]-'a'][n]-f[s[i]-'a'][i-1]);
    printf("%lld\n", ans+1);
    return 0;
}
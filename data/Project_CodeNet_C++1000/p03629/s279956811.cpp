# include <cstdio>
# include <cstring>

using namespace std;

const int MAX_N = 2e5 + 10;

int n;
char s[MAX_N];

int dp[MAX_N];
char f[MAX_N];
int nt[MAX_N];
int last[26];

int main ()
{
    int i, j;
    scanf ("%s", s + 1);
    n = strlen (s + 1);

    for (i = 0; i < 26; i ++)
        last[i] = n + 1;

    dp[n + 1] = (1 << 30);
    dp[n + 2] = 0;

    for (i = n; i >= 1; i --)
    {
        dp[i] = (1 << 30);
        last[s[i] - 'a'] = i;
        for (j = 0; j < 26; j ++)
        {
            if (dp[i] > (dp[last[j] + 1] + 1))
            {
                dp[i] = dp[last[j] + 1] + 1;
                f[i] = char (j + 'a');
                nt[i] = last[j] + 1;
            }
        }
    }

    int x = 1;

    while (x <= n)
    {
        printf ("%c", f[x]);
        x = nt[x];
    }
    printf ("\n");

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int compute (vector < int > s)
{
    int n = s.size (), dp[209][209], ans = 0;
    for (int frst = 0; frst < n; frst ++)
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dp[i][j] = 0;
        for (int i=0; i<frst; i++)
            dp[i][frst] = (i > 0 ? dp[i - 1][frst] : 0) + (s[i] == s[frst]);
        for (int i=0; i<frst; i++)
            for (int j=frst + 1; j<n; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (i > 0) adto (dp[i][j], dp[i - 1][j]);
                if (s[i] != s[j] && i > 0 && j > 0) dp[i][j] = subtract (dp[i][j], dp[i - 1][j - 1]);
            }
        adto (ans, dp[frst - 1][n - 1]);
    }
    return ans;
}

int computeOtherWay (vector < int > p)
{
    int N = p.size (), ans = 0, dp[209];
    for (int i=0; i<N; i++)
    {
        dp[i] = 1;
        for (int j=0; j<i; j++)
            if (p[j] < p[i])
                adto (dp[i], dp[j]);
        adto (ans, dp[i]);
    }
    return ans;
}

vector < int > solve (long long K)
{
    vector < int > ans;
    if (K == 1)
    {
        ans.push_back (1);
        return ans;
    }
    if (K & 1)
    {
        ans = solve (K / 2);
        ans.push_back (ans.size () + 1);
    }
    else
    {
        ans = solve (K - 1);
        for (int i=0; i<ans.size (); i++)
            ans[i] ++;
        ans.push_back (1);
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

long long K;
scanf ("%lld", &K);
vector < int > P = solve (K), ans;
for (int i=1; i<=P.size (); i++)
    ans.push_back (i);
for (auto val : P)
    ans.push_back (val);
printf ("%d\n", ans.size ());
for (int i=0; i<ans.size (); i++)
    printf ("%d%c", ans[i], " \n"[i == ans.size () - 1]);
//printf ("=%d\n", compute (ans));
/*int N = 8, p[10];
set < int > S;
for (int i=1; i<=N; i++)
    p[i] = i;
do {
    vector < int > currP, inp;
    for (int i=1; i<=N; i++)
        inp.push_back (i);
    for (int i=1; i<=N; i++)
        currP.push_back (p[i]), inp.push_back (p[i]);
    int logicalValue = computeOtherWay (currP), sureValue = compute (inp);
    if (logicalValue != sureValue)
    {
        printf ("WA\n");
        return 0;
    }
    S.insert (logicalValue);
}while (next_permutation (p + 1, p + N + 1));
for (auto it : S)
    printf ("%d\n", it);*/
/*int n, x;
scanf ("%d", &n);
vector < int > inp, p;
for (int i=1; i<=n; i++)
    inp.push_back (i);
for (int i=1; i<=n; i++)
{
    int x;
    scanf ("%d", &x);
    inp.push_back (x), p.push_back (x);
}
printf ("%d\n%d\n", compute (inp), computeOtherWay (p));
return 0;*/

/*int l;
scanf ("%d", &l);
while (l --)
    scanf ("%d", &x), inp.push_back (x);
printf ("%d\n", compute (inp));
return 0;*/
/*for (int n=1; n<=10; n++)
{
    inp.push_back (1), inp.push_back (2), inp.push_back (3);
    printf ("%d\n", compute (inp));
}*/
return 0;
}

#include <bits/stdc++.h>
#define newline printf ("\n")
#define space printf (" ")
#define cinfalse ios::sync_with_stdio(false)
#define fread(a) freopen (a".in", "r", stdin), freopen(a".out", "w", stdout)
#define rint register int
#define For(i, a, b) for (rint i = a; i <= b; i ++)
#define Low(i, a, b) for (rint i = a; i >= b; i --)
#define FFr(i, a, b, c) for (rint i = a; i <= b; i += c)
#define FLw(i, a, b, c) for (rint i = a; i >= b; i -= c)
#define min(a, b) (a)>(b)?(b):(a)
#define max(a, b) (a)>(b)?(a):(b)
using namespace std;
char a[100010];
int la;
int main()
{
    gets(a);
    la = strlen(a);
    For (i, 0, la/2)
    {
        rint l = i, r = la - i - 1;
        if(a[l]=='b' && a[r]=='d' || a[l]=='d' && a[r]=='b' || a[l]=='p' && a[r]=='q' || a[l]=='q' && a[r]=='p');
        else return puts("No"), 0;
    }
    printf("Yes");
    return 0;
}
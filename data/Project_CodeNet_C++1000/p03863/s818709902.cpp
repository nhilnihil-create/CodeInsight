#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

char s[100050];

int work() {
    scanf("%s", s);
    int n = strlen(s);
    if (s[0] == s[n-1]) n++;
    if (n % 2 == 0) printf("Second\n");
    else printf("First\n");
    return 0;
}

int main() {
    work();
    //while (~scanf("%d", &n)) work();
    //scanf("%d", &T); while (T--) work();

    return 0;
}

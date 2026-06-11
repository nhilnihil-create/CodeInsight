#include<cstdio>
#include<cstring>

const int MAX = 1e5;
char s[MAX];
int main() {
    scanf("%s", s);
    int l = strlen(s);
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'p') cnt++;
    }

    printf("%d\n", l / 2 - cnt);
    return 0;
}

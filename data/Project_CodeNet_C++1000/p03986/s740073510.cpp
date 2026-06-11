#include <bits/stdc++.h>
using namespace std;
#define N 2000010
char s[N], sta[N];
int top;
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        if (top) {
            if (s[i] == 'S')
                sta[++top] = 'S';
            else if (sta[top] == 'S')
                top--;
            else
                sta[++top] = 'T';
        } else
            sta[++top] = s[i];
    printf("%d\n", top);
    return 0;
}

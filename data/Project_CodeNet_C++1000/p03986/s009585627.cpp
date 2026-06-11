#include <bits/stdc++.h>

using namespace std;

char s[200005];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    stack<char> stac;
    for (int i = 0; i < n; ++i) {
        if (!stac.empty() && stac.top() == 'S' && s[i] == 'T') stac.pop();
        else stac.push(s[i]);
    }

    printf("%d\n", stac.size());
    
    return 0;
}

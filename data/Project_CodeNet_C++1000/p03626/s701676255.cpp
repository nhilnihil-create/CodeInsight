#include<cstdio>
#include<vector>
using namespace std;

const int A = 1e9 + 7;
int n;
char s[2][53];
vector<bool> v;

int main() {
    scanf("%d", &n);
    scanf("%s", s[0]);
    scanf("%s", s[1]);
    for (int i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) {
            v.push_back(true);
            i++;
        }
        else v.push_back(false);
    }
    
    int ans;
    if (v.front()) ans = 6;
    else ans = 3;
    for (int i = 1, s = v.size(); i < s; i++) {
        if (!v[i - 1]) ans = static_cast<long>(ans) * 2 % A;
        else if (v[i]) ans = static_cast<long>(ans) * 3 % A;
    }

    printf("%d\n", ans);
    return 0;
}


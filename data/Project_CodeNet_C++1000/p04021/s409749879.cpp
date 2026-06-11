#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> un;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end());
    for (int i = 1; i < n; i += 2) {
        int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        if (ind % 2 == 0) res++;
    }
    printf("%d\n", res);
    return 0;
}

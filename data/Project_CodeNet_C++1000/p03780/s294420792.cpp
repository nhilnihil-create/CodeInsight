#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int n, k;
int a[5000];
bool jdg[5000];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n, [](const int &i1, const int &i2)->bool {
        return i1 > i2;
    });
    
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            jdg[i] = true;
            continue;
        }
        int sum = a[i];
        vector<int> ind;
        ind.push_back(i);
        for (int j = i + 1; j < n; j++) {
            if (sum + a[j] >= k) {
                jdg[j] = true;
                for (auto &l : ind) jdg[l] = true;
                ind.clear();
            }
            else {
                sum += a[j];
                ind.push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!jdg[i]) ans++;
    }

    printf("%d\n", ans);
    return 0;
}

#include <fstream>
#include <vector>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 500;

int answer[1 + MAXN * MAXN];
bool marked[1 + MAXN * MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        marked[x] = true;
        answer[x] = i;
    }
    for (int i = 1, j = 1; i <= n * n; i++)
        if (marked[i]) {
            int x = answer[i], need = x - 1;
            while (j < i && need) {
                if (!answer[j]) {
                    answer[j] = x;
                    need--;
                }
                j++;
            }
            if (need) {
                printf("No\n");
                return 0;
            }
        }
    for (int i = n * n, j = n * n; i >= 1; i--)
        if (marked[i]) {
            int x = answer[i], need = n - x;
            while (j > i && need) {
                if (!answer[j]) {
                    answer[j] = x;
                    need--;
                }
                j--;
            }
            if (need) {
                printf("No\n");
                return 0;
            }
        }
    printf("Yes\n");
    for (int i = 1; i <= n * n; i++)
        printf("%d ", answer[i]);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;

int main() {
    string snuke = "snuke";
    int A, B;
    char c = 65;    // A
    if (scanf("%d %d", &A, &B) < 2) return 0;

    char tmp[8];
    bool flg = false;
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (scanf("%s", tmp) < 1) return 0;
            if (tmp == snuke)
            {
                c = c + j;
                printf("%c%d\n", c, i + 1);
                flg = true;
                break;
            }
        }
        if (flg) break;
    }
    return 0;
}

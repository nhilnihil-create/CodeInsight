#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int s5 = 0, s7 = 0, t;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &t);
        if (t == 5) s5 += 5;
        else if (t == 7) s7 += 7;
    }
    (s5 + s7 == 17) ? printf("YES\n") : printf("NO\n");
    return 0;
}

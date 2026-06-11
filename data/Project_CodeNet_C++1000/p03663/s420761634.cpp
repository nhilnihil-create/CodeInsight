#include <stdio.h>
#define N (2000)
char s[N], ans[N], s2[N];
int main(){
    int len = 0;
    s[0] = '1';
    for (int i = 1; i < 12; i++){
        s[i] = '0';
        s[i + 1] = 0;
        printf("? %s\n", s);
        fflush(stdout);
        scanf("%s", ans);
        if (ans[0] == 'N'){
            len = i;
            break;
        }
    }
    if (len == 0){
        for (int i = 0; i < 12; i++){
            s2[i] = '9';
            s2[i + 1] = 0;
            printf("? %s\n", s2);
            fflush(stdout);
            scanf("%s", ans);
            if (ans[0] == 'Y'){
                len = i + 1;
                break;
            }
        }
        if (len == 1){
            printf("! 1\n");
            fflush(stdout);
            return 0;
        }
    }
    for (int i = 0; i < len - 1; i++){
        char l = '0', r = '9' + 1;
        s[i + 1] = 0;
        while (l + 1 < r){
            char mid = l + r >> 1;
            s[i] = mid;
            printf("? %s\n", s);
            fflush(stdout);
            scanf("%s", ans);
            if (ans[0] == 'Y'){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        s[i] = l;
    }
    s[len] = '0';
    s[len + 1] = 0;
    char l = '0' - 1, r = '9';
    while (l + 1 < r){
        char ed = l + r >> 1;
        s[len - 1] = ed;
        printf("? %s\n", s);
        fflush(stdout);
        scanf("%s", ans);
        if (ans[0] == 'Y'){
            r = ed;
        }
        else {
            l = ed;
        }
    }
    s[len - 1] = r;
    s[len] = 0;
    printf("! %s\n", s);
    fflush(stdout);
}
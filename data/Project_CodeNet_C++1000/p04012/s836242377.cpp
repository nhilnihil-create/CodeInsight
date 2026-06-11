#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[100];
    scanf("%s", &str);

    int len = strlen(str);
    int c = 0;
    int i = 0;
    while(i < len) {
        if(count(str, str + len, str[i]) % 2 == 0) {
            c++;

            if(c == len) {
                printf("Yes");
            }
        } else {
            printf("No");
            break;
        }
        i++;
    }
    return 0;
}
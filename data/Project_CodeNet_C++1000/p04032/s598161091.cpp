#include <stdio.h>
#include <string.h>
char s[100001];
int words[30]={};
int main(){
    scanf("%s",s);
    int len=strlen(s);
    if (s[0]==s[1]) {
        printf("1 2");
        return 0;
    }
    words[s[0]-'a']++,words[s[1]-'a']++;
    for (int i=2; i<len; i++) {
        if ((++words[s[i]-'a'])>1) {
            printf("%d %d\n",i-1,i+1);
            return 0;
        }
        words[s[i-2]-'a']--;
    }
    printf("-1 -1");
}
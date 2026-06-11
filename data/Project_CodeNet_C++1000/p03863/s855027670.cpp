#include<cstdio>
const int N=100001;
int main() {
    int n=3;
    char s[N];
    scanf("%s",s);
    while(s[n])n++;
    printf((s[0]==s[n-1] ^ n&1)?"First":"Second");
    return 0;
}

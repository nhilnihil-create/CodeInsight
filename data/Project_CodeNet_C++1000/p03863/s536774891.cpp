#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000005];int n;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    printf("%s",((s[1]==s[n])^((n&1)==0))?"Second\n":"First\n");
    return 0;
}

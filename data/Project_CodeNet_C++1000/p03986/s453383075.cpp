#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
const int maxN=200005;
char s[maxN];
int main(int argc, const char * argv[]) {
    while(scanf("%s",s)!=EOF){
        int k=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='T'&&k>0)k--;
            else if(s[i]=='S')k++;
            
        }
        printf("%d\n",2*k);
    }
    return 0;
}
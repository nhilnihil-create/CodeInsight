#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
char c[222];
scanf("%s", c);
int n=strlen(c);
for(int i = n-2;i;i-=2){
if(strncmp(c, c+i/2, i/2)==0){
    printf("%d\n",i);
    return 0;
}

}

return 0;
}
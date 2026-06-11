#include <bits/stdc++.h>

using namespace std;

char a[100010];
int la ;

int main(){
    gets(a);
    la = strlen(a);
    for (int i = 0; i <= la/2; i++){
        int l = i,r = la-i-1;
        if(a[l] == 'b' && a[r] == 'd' || a[l] == 'd' && a[r] == 'b' || a[l] == 'p' && a[r] == 'q' || a[l] == 'q' && a[r] == 'p');
        else{
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
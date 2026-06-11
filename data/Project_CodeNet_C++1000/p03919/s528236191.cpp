#include <bits/stdc++.h>
using namespace std;

long long int H, W, i, j;
char c[6], an[6] = "snuke";

int main(){
    scanf("%lld%lld", &H, &W);
    for(; i < H; i++){
        for(j = 0; j < W; j++){
            scanf(" %s", &c);
            if(!strcmp(c, an)) cout << char(65 + j) << i + 1 << endl;
        }
    }
    return 0;
}

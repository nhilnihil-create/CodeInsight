#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> vip(n+1);
    for(int i = 1; i < n+1; i++){
        scanf("%d", &vip[i]);
    }
    vector<int> viq(n+1);  //p_iの逆写像
    for(int i = 1; i < n+1; i++){
        viq[vip[i]] = i;
    }
    for(int i = 1; i < n+1; i++){
        printf("%d ", i * n + viq[i]);
    }
    printf("\n");
    for(int i = 1; i < n+1; i++){
        printf("%d ", (n - i) * n + 1);
    }
    return 0;
}

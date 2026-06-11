#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    for(int i = 0 ; i < 3; ++i){
        scanf("%d",a + i);
    }
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < 3; ++j){
            for(int k = 0 ; k < 3; ++k){
                if(a[i] + a[j] == a[k]){
                    puts("Yes");
                    return 0;
                }
            }
        }
    }
    puts("No");
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int A, B, C;
ll Now;


int main(){
    scanf("%d",&n);
    bool is_B = false;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &Now);
        if(Now % 2 == 0){
            if(Now % 4 == 0) A++;
            else is_B = true;
        }
        else C++;
    }
    if(is_B) C++;
    if(A - C >= -1) printf("Yes");
    else printf("No");
    return 0;
}

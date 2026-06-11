#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int p[101010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        p[i] = i == p[i];
        if(p[i])p[i] = p[i-1]+1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(p[i] != 0 && p[i+1] == 0){
            ans += (p[i]+1)/2;
        }
    }
    printf("%d\n", ans);
}

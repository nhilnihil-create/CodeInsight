#include <cstdio>
using namespace std;
int n,m;
int arr[100005];
int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        arr[a]++;
        arr[b]++;
    }
    
    for (int x=0;x<n;x++){
        if (arr[x]&1) {
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
}
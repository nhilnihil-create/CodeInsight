#include <bits/stdc++.h>

using namespace std;

void pung() {
    puts("Impossible");
    exit(0);
}

int n, m;
int arr[110];

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) scanf("%d",&arr[i]);
    int c = 0;
    for (i=0;i<m;i++) c += arr[i]%2;
    if (c>2) pung();
    int f = 0;
    for (i=0;i<m;i++) {
        if (arr[i]%2) {
            swap(arr[i],arr[f?m-1:0]);
            f++;
        }
    }
    for (i=0;i<m;i++) printf("%d ",arr[i]);
    printf("\n");
    printf("%d\n",(m==1?2:m)+(arr[0]==1?-1:0));
    if (m==1) {
        if (arr[0]==1) printf("1\n");
        else printf("%d %d\n",arr[0]-1,1);
        return 0;
    }
    for (i=0;i<m;i++) {
        int v = arr[i]-(i==0)+(i==m-1);
        if (v) printf("%d ",v);
    }
    printf("\n");

    return 0;
}

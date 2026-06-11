#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
#define F first
#define S second
int n;
int p[250005];
P a[505];
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].F);
        a[i].S=i+1;
    }
    sort(a,a+n);
    int q=1;
    for(int i=0;i<n;i++){
        int v=a[i].S,o=a[i].F;
        p[o]=v;
        for(int j=0;j<v-1;j++){
            while(p[q]>0)q++;
            if(q>o){
                printf("No\n");
                return 0;
            }
            p[q]=v;
        }
    }
    q=1;
    for(int i=0;i<n;i++){
        int v=a[i].S,o=a[i].F,s=n-v;
        for(int j=0;j<s;j++){
            while(p[q]>0)q++;
            if(q<o){
                printf("No\n");
                return 0;
            }
            p[q]=v;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n*n;i++){
        printf("%d",p[i]);
        if(i!=n*n)printf(" ");
    }
    printf("\n");
}
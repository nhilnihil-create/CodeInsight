#include<bits/stdc++.h>
using namespace std;

#define maxn 100000
#define maxm 200000

int n,m;
int a[maxm+5];
int c[maxm+5];

void readin(){
    scanf("%d",&n);
    m=n*2-1;
    for(int i=1;i<=m;i++) {
        scanf("%d",&a[i]);
    }
}

void Turn(int x) {
    for(int i=1;i<=m;i++){
        c[i]=(a[i]>=x);
    }
}

bool judge(int x){
    Turn(x);
    int p1=0,p2=m+1;
    for(int i=n;i>=2;i--){
        if(c[i]==c[i-1]){
            p1=i;
            break;
        }
    }
    for(int i=n;i<m;i++) {
        if(c[i]==c[i+1]) {
            p2=i;
            break;
        }
    }
    if(p1==0&&p2==m+1) return c[1];
    if(n-p1>p2-n) return c[p2];
    else return c[p1]; 
}

int binsearch() {
    int l=0,r=m;
    while(l+1<r) {
        int mid=l+(r-l)/2;
        if(judge(mid)) l=mid;
        else r=mid;
    }
    if(judge(l+1)) return l+1;
    if(!judge(l)) return l-1;
    else return l;
}

int main(){
    readin();
    int ans=binsearch();
    printf("%d",ans);
    return 0;
}
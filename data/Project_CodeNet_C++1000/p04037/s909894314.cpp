#include <bits/stdc++.h>

using namespace std;

bool cmp(int a,int b) {
    return a>b;
}
int x[100010];

int main() {
//    freopen("in","r",stdin);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        scanf("%d",&x[i]);
    }
    sort(x+1,x+1+n,cmp);
    int i;
    for(i=1; i<=n; i++) {
        if(i+1>x[i+1])break;
    }
    int sg=0;
    for(int j=1+i; x[j]==i; j++)
        sg^=1;
    sg|=(x[i]-i)&1;
    if(sg)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli pw[11];
int main() {
    pw[0]=1;
    for(int i=1;i<11;i++) pw[i]=pw[i-1]*10;

    int arr[11]={0,};
    for(int s=0;s<11;s++) {
        int lo=(s==0 ? 0 : -1), up=9;
        lli v=0;
        for(int i=0;i<s;i++) v=v*10+arr[i];
        
        while(up-lo>1) {
            int md=(lo+up)>>1;
            
            lli tv=v*10+md;
            for(int i=s;i<11;i++) tv=tv*10+9;
            printf("? %lld\n",tv);
            fflush(stdout);
            
            char str[11];
            scanf("%s",str);
            if(str[0]=='Y') up=md;
            else lo=md;
        }
        arr[s]=up;
    }

    lli ans=0,s;
    if(arr[0]==1) s=2;
    else s=1;

    for(int i=0;i<11;i++) {
        printf("? %lld\n",s*pw[i]);
        fflush(stdout);
        
        char str[10];
        scanf("%s",str);
        if(arr[0]==1 && str[0]=='Y') {
            for(int j=0;j<=i;j++) ans=ans*10+arr[j];
            break;
        }
        if(arr[0]!=1 && str[0]=='N') {
            for(int j=0;j<i;j++) ans=ans*10+arr[j];
            break;
        }
    }
    printf("! %lld\n",ans);
    fflush(stdout);

    return 0;
}

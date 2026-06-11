#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=1e5+10;
void solve(int n,int *a){
    int num=0,cnt[MAX],ans=0,odd=0,even=0;
    for(int i=1,j=0;i<=n;i++){
        if(a[i]!=a[j]||i==n){
            cnt[num]=i-j;
            j=i;
            if(cnt[num]&1)
                odd++;
            else
                even++;
            num++;
        }
    }
    ans=num;
    if(even&1)
        ans--;
    cout<<ans<<endl;
}
int main(){
    int n,a[MAX];
    while(cin>>n){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        solve(n,a);
    }
    return 0;
}

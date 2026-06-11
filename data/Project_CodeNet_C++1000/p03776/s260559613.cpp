#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,L,R,a[55],ans1,ans2,cnt1,cnt2;
bool cmp(int a,int b){
	return a>b;
}
int C[55][55];
void init(){
    C[0][0]=1;
    for(int i=1;i<=50;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
}
signed main(){
    init();
    cin>>n>>L>>R;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=L;i++) ans1+=a[i];
    for(int i=1;i<=n;i++) if(a[i]==a[L]) cnt1++;
    for(int i=1;i<=L;i++) if(a[i]==a[L]) cnt2++;
    if(a[1]==a[L])
        for(int i=L;i<=R;i++) ans2+=C[cnt1][i];
    else ans2=C[cnt1][cnt2];
    printf("%lf\n%lld",(double)ans1/L,ans2);
}
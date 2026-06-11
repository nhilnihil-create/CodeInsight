#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MAX=200004;
int cnt[MAX],fin,n,c;
main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&cnt[i]);
        if(cnt[i]==i) c++;
        else fin+=(c+1)/2, c=0;
    }
    fin+=(c+1)/2;
    printf("%d\n",fin);
}

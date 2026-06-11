#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n;
int p[max_n];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    int ans=0;
    for(int i=1;i<n;i++){
        if(p[i]==i){
            ans++;
            swap(p[i],p[i+1]);
        }
    }
    if(p[n]==n)ans++;
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
void dfs(long long a,long long b){
    if(a%b==0){
        ans+=a*2-b;//不可再拆
        return;
    }
    ans+=a/b*b*2;//拆成更小的
    dfs(b,a%b);//更小的
    return;
}
int main(){
    cin>>n>>x;
    if(x>=n-x)dfs(x,n-x);
    else dfs(n-x,x);
    cout<<ans+n<<endl;//最大的两条边
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    int n;cin>>n;
    int l[2*n];
    for(int i=0;i<2*n;i++) cin>>l[i];
    sort(l,l+2*n,greater<int>());
    int ans=0;
    for(int i=1;i<2*n;i+=2){
        ans+=l[i];
    }
    cout<<ans<<endl;
    return 0;
}
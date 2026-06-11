#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void Solve(int n,int* a,int sum){
    int q;
    cin>>q;
    while(q--){
        int x,y,ans=0;
        cin>>x>>y;
        cout<<sum-a[x]+y<<endl;
    }
}

int main(){
    int n;
    while(cin>>n){
        int a[128],sum=0;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        Solve(n,a,sum);
    }
    return 0;
}

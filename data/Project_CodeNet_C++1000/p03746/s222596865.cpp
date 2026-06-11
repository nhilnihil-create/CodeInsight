#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int main(){
    int n,m,a,b;
    vec A[200001];
    cin>>n>>m;
    rep(i,m) cin>>a>>b,A[a].push_back(b),A[b].push_back(a);
    deque<int> ans;
    int num[200001]={0};
    ans.push_back(1);
    ans.push_back(A[1][0]);
    num[1]=1;
    num[A[1][0]]=1;
    while(true){
        int z=1,a;
        for(auto i:A[ans.front()]) if(num[i]==0) z=0,a=i;
        if(z==0){
            ans.push_front(a);
            num[a]=1;
            continue;
        }
        for(auto i:A[ans.back()]) if(num[i]==0) z=0,a=i;
        if(z==0){
            ans.push_back(a);
            num[a]=1;
            continue;
        }
        cout<<ans.size()<<"\n";
        for(auto i:ans) cout<<i<<" ";
        break;
    }
}
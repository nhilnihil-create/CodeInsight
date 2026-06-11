#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int N = 1e5+5;
int a[N];
vector<int>v[N];
vector<pair<int,int> >ask[N];
int h[N];
int sol[N];
vector<int>trt;
int bs(int y){
    int st = 0;
    int en = trt.size();
    int ret = 0;
    while(st<=en){
        int mid = (st+en)/2;
        if(trt[mid]>=y){
            ret = max(ret,mid);
            st = mid+1;
        }
        else{
            en= mid-1;
        }
    }
    return trt.size()-ret;
}
void dfs(int x){
    for(auto p:ask[x]){
        int c = p.fi;
        sol[p.se] = bs(c);
        sol[p.se] = max(sol[p.se],1);
    }
    trt.push_back(x);
    for(int y : v[x]){
        h[y] = h[x]-1;
        dfs(y);
    }
    trt.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l;
    cin>>l;
    for(int i=1;i<n;i++){
        int st = i;
        int en = n;
        int ans = i;
        while(st<=en){
            int mid  = (st+en)/2;
            if(a[mid]-a[i]<=l){
                ans = max(ans,mid);
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        v[ans].pb(i);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        ask[x].pb({y,i});

    }
    dfs(n);
    for(int i=0;i<q;i++)cout<<sol[i]<<endl;
    return 0;
}

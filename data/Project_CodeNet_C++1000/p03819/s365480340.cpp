#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 400000
using namespace std;
//区間加算
static const int MAX_SIZE = 1 << 19; //segment tree のサイズ。 2^19 ≒ 5.2 * 10^5
ll all[2 * MAX_SIZE - 1], part[2 * MAX_SIZE - 1]; // segment tree
//区間[a, b)に値xを加算する.
void add(int a, int b, int x, int k, int l, int r)
{
    if (a <= l && r <= b){ //[l, r)が[a, b)に完全に内包されていれば
        all[k] += x; //[l, r)の全ての区間が持つ値としてxを足す.
    }
    else if (l < b && a < r){ //[l, r)と[a, b)が交差していれば
        part[k] += (min(b, r) - max(a, l)) * x;  //交差している分の値を, 部分的な和を持つノードに加算する.
        add(a, b, x, k * 2 + 1, l, (l + r) / 2); //子でも同じ処理を行う.
        add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃.
    }
}
void ADD(int a,int b,int x){
    add(a,b,x,0,0,MAX_SIZE);
}
ll sum(int a, int b, int k, int l, int r)
{
    if (b <= l || r <= a){ //[a, b)と[l, r)が全く交差しない場合
        return (0);
    }
    else if (a <= l && r <= b){ //完全に内包されていれば
        return (all[k] * (r - l) + part[k]);
    }
    else { //[l, r)と[a, b)が交差していれば
        ll res;
        res = (min(b, r) - max(a, l)) * all[k]; //そのノードの全ての要素が持つ値のうち, [a, b)に属すものの分だけを加算する.
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2); //子ノードで和を求める.
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r); //〃
        return (res);
    }
}
//[a,b)の和を求める
ll SUM(int a,int b){
    return sum(a,b,0,0,MAX_SIZE);
}
struct line{
    int length,left,right;
    bool operator<(const line& x){
        return (length<x.length);
    }
};
main(){
    int n,m;
  	cin>>n>>m;
    line l[N];
    rep(i,n){
        cin>>l[i].left>>l[i].right;
        l[i].length=(l[i].right-l[i].left+1);
    }
    sort(l,l+n);
    int num=n,temp=0;
    rep2(i,1,m){
        while(l[temp].length<i&&temp<n){
            num--;
            add(l[temp].left,l[temp].right+1,1,0,0,MAX_SIZE);
            temp++;
        }
        int ans=num;
        for(int j=0;j<=m;j+=i){
            ans+=sum(j,j+1,0,0,MAX_SIZE);
        }
        cout<<ans<<endl;
    }
}
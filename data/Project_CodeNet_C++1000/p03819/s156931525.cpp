#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010;
const double EPS=1e-9;
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};
struct BinaryIndexedTree{
    vector<int> bit;
    BinaryIndexedTree(int siz){
        bit.assign(++siz,0);
    }
    void add(int k,int x){
        for(++k;k<bit.size();k+=k&-k){
            bit[k]+=x;
        }
    }
    int sum(int k){
        int res=0;
        for(++k;k>0;k-=k&-k){
            res+=bit[k];
        }
        return res;
    }
};
vector<tuple<int,int,int>> v;
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        v.push_back(make_tuple(r-l+1,l,r));
    }
    sort(all(v));
    BinaryIndexedTree bit(2*m);
    int id=0;
    for(int i=1;i<=m;i++){
        while(get<0>(v[id])<i&&id<n){
            bit.add(get<1>(v[id]),1);
            bit.add(get<2>(v[id])+1,-1);
            id++;
        }
        int res=n-id;
        for(int j=i;j<=m;j+=i){
            res+=bit.sum(j);
        }
        cout<<res<<endl;
    }
}
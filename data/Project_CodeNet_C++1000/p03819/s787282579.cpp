#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e5+5;
int lazy[MAXN];
int seg[MAXN];
vector<pair<int,int>> v1[MAXN];
void push(int curr){
    if(lazy[curr]){
        lazy[2*curr] += lazy[curr];
        lazy[2*curr+1] += lazy[curr];
        seg[2*curr] += lazy[curr];
        seg[2*curr+1] += lazy[curr];
        lazy[curr]= 0;
    }
}
void build(int curr,int l,int r){
    if(l==r){
        seg[curr] = 0;
        lazy[curr] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*curr,l,mid);
    build(2*curr+1,mid+1,r);
    seg[curr] = seg[2*curr]+seg[2*curr+1];
}
void update(int curr,int l,int r,int tl,int tr){
    
    if(l>tr||r<tl){
        return;
    }
    if(l!=r){
        push(curr);
    }
    if(tl<=l && r<=tr){
        seg[curr] ++;
        lazy[curr]++;
        return;
    }
    long long mid = (l+r)/2;
    update(2*curr,l,mid,tl,tr);
    update(2*curr+1,mid+1,r,tl,tr);
    seg[curr] = seg[2*curr]+seg[2*curr+1];
}
int query(int curr,int l,int r,int tl,int tr){
    if(l>tr||r<tl){
        return 0;
    }
    if(l!=r){
        push(curr);
    }
    if(tl<=l && r<=tr){
        return seg[curr];
    }
     long long mid = (l+r)/2;
     int a = query(2*curr,l,mid,tl,tr);
     int b = query(2*curr+1,mid+1,r,tl,tr);
     seg[curr] = seg[2*curr]+seg[2*curr+1];
     return a+b;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        int sz = r-l+1;
        v1[sz].push_back(make_pair(l,r));
    }
    build(1,1,m);
    int tot = 0;
    for(int i=1;i<=m;i++){
        for(auto x:v1[i]){
            tot++;
            
            update(1,1,m,x.first,x.second);
            //cout<<123<<" "<<x.first<<" "<<x.second<<" "<<query(1,1,m,2,2)<<endl;
        }
        int temp = 0;
        for(int j=i;j<=m;j+=i){
            
            temp+=query(1,1,m,j,j);
            
        }
        cout<<temp+(n-tot)<<endl;
    }
}
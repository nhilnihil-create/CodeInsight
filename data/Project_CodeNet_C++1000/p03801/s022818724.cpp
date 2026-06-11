#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 3e5+5;
long long seg[4*MAXN];
long long arr[MAXN];
long long cnt = 0;
long long ans[MAXN];
void build(long long curr,long long l,long long r){
    if(l==r){
        seg[curr] = arr[l];
        return;
    }
    long long mid = (l+r)/2;
    build(2*curr,l,mid);
    build(2*curr+1,mid+1,r);
    seg[curr] = max(seg[2*curr],seg[2*curr+1]);
}
long long query(long long curr,long long l,long long r){
    if(l==r){
        return l;
    }
    long long mid = (l+r)/2;
    if(seg[2*curr+1] == seg[curr]){
        return query(2*curr+1,mid+1,r);
    }else{
        return query(2*curr,l,mid);
    }
}
void update(long long curr,long long l,long long r,long long ind){
    if(l==r){
        seg[curr] = 0;
        return;
    }
    long long mid = (l+r)/2;
    if(ind<=mid){
        update(2*curr,l,mid,ind);
    }else{
        update(2*curr+1,mid+1,r,ind);
    }
    seg[curr] = max(seg[2*curr],seg[2*curr+1]);
}
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    long long ind2 = n;
    while(true){
        long long mx = seg[1];
      
        long long ind = query(1,1,n);
        ind2 = min(ind2,ind);
        update(1,1,n,ind);
        if(mx == 0){
            break;
        }
        cnt++;
        //cout<<seg[1]<<endl;
        while(seg[1] == mx){
            ind = query(1,1,n);
            ind2 = min(ind2,ind);
            update(1,1,n,ind);
            cnt++;
        }
        long long next = seg[1];
       // cout<<ind2<<endl;
        ans[ind2] += 1LL*cnt*(mx-next);
    }
    for(long long i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

lint segdata[(1<<22)-1];
lint lazy[(1<<22)-1];

lint powmod(lint a,lint b){
  return b?powmod(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;
}
lint mod2=powmod(2,MOD-2);

lint neutral(){
    return 0; //単位元
}
lint calc(lint a,lint b){
    return (a+b)%MOD; //演算
}
void seginit(){
    rep(i,(1<<22)-1) segdata[i]=neutral();
}
void update(lint i,lint x){ // i番目の値をxに更新 rangeadd()の後に使ったらだめ 単位元が0以外の時だけ使う
    i+=(1<<21)-1;
    segdata[i]=x;
    while(i>0){
        i=(i-1)/2;
        segdata[i]=calc(segdata[i*2+1],segdata[i*2+2]);
    }
}
void eval(lint k,lint l,lint r){
    if(lazy[k]){
        segdata[k]=(segdata[k]+lazy[k])%MOD;
        if(r-l>1) lazy[2*k+1]=(lazy[2*k+1]+lazy[k]*mod2)%MOD,lazy[2*k+2]=(lazy[2*k+2]+lazy[k]*mod2)%MOD;
        lazy[k]=0;
    }
}
void add(lint a,lint b,lint x,lint k,lint l,lint r){
    eval(k,l,r);
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){
        lazy[k]=(lazy[k]+(r-l)*x)%MOD;
        eval(k,l,r);
    }
    else{
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        segdata[k]=calc(segdata[2*k+1],segdata[2*k+2]);
    }
}
lint seg(lint a,lint b,lint k,lint l,lint r){
    eval(k,l,r);
    if(r<=a || b<=l) return neutral();
    if(a<=l && r<=b) return segdata[k];
    else{
        lint left=seg(a,b,k*2+1,l,(l+r)/2);
        lint right=seg(a,b,k*2+2,(l+r)/2,r);
        return calc(left,right);
    }
}
lint query(lint a,lint b){
    return seg(a,b+1,0,0,1<<21)%MOD; //a~b(閉区間）の範囲での演算
}
void rangeadd(lint a,lint b,lint x){ //a~b(閉区間)にxを加算
    add(a,b+1,x,0,0,1<<21); 
    return;
}

lint other[1100000];
lint fin[1100000];

int main(void){
    seginit();
    lint N;
    cin >> N;
    update(0,1);
    for(int i=0;i<N;i++){
        lint before=query(i,i)%MOD;
        rangeadd(i+1,i+1,before);
        if(i+3<=i+N+1 && i<=N-2) rangeadd(i+3,i+N+1,before);
        other[i+1]=(before*(N-1))%MOD;
        fin[i+1]=(other[i]*(N-1)+fin[i])%MOD;
    }
    cout << (query(N,2*N)+other[N]+fin[N])%MOD << endl;
}
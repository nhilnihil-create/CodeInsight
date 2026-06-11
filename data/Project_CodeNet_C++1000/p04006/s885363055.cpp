#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 1100000000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;

const int MAX_N=1<<17;

//セグメント木を持つグローバル配列
ll n,dat[2*MAX_N-1];

//初期化
void init(int n_){
    //簡単のために要素数を2のべき乗に
    n=1;
    while(n<n_) n*=2;

    //全ての値をINT_MAXに
    for(int i=0;i<2*n-1;i++) dat[i]=2000000000;
}

//k番目の値(0-indexed)をaに変更
void update(int k,ll a){
    //葉の節点
    k+=n-1;
    dat[k]=a;
    //登りながら更新
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}

//[a,b)の最小値を求める
//後ろの方の引数は、計算の簡単のための引数
//ｋは接点の番号、l,rはその接点が[l,r)に対応づいていることを表す
//したがって、外からはquery(a,b,0,0,n)として呼ぶ
ll query(int a,int b,int k,int l,int r){
    //[a,b)と[l,r)が交差しなければ,INT_MAX
    if(r<=a || b<=l) return 2000000000;

    //[a,b)が[l,r)を完全に含んでいれば、この節点の値
    if(a<=l && r<=b) return dat[k];
    else{
        //そうでなければ、２つの子の最小値
        ll vl=query(a,b,k*2+1,l,(l+r)/2);
        ll vr=query(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}

int main(){
    int N;
    ll a[2100],x,ans=1000000000000000,temp=0;
    cin>>N>>x;
    init(N+2);
    for(int i=0;i<N;i++){
        cin>>a[i];
        update(i,a[i]);
    } 
    for(int i=0;i<N;i++,temp=0){
        for(int j=0;j<N;j++){
            if(j+i>=N) temp+=min(query(j,N,0,0,n),query(0,j+i+1-N,0,0,n));
            else temp+=query(j,j+i+1,0,0,n);
        }
        temp+=x*i;
        ans=min(ans,temp);
    }

    cout<<ans<<endl;
}

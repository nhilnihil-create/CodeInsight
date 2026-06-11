#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX =510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2; i<MAX; i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

ll COM(int n, int k){
  if(n<k)
    return 0;
  if(n<0 || k<0)
    return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

//2 3 1 1
//...
//x..
//DPっぽいなあ
//111
//X12

//.....
//.....
//XX...
//XX...
//XX...

//11111
//12345
//0037-
//00

//10000*10000の処理で4sec。TLE・・・
//0は境界値だけにして、探索も0以外の長方形2つに限るとか
//でも使用メモリと時間が圧倒的にまだ多いっぽ
//DP自体は1行の上書きでいけるからメモリは減らせる
//時間は･･･。
//1 1 1 1 1
//1 2 3 4 5
//1 3 6 10 15
//1 4 10 20 35
//1 5 15 35 70
//なんの法則あるかな ななめで見れば2項係数か
//はなれてる距離nCkを、2*W回でいけるかな
//8回動く。r5d3 8C3
//そう単純でもないっぽい
//. . . . .
//. . . . .
//X X . . .
//X X . . .
//X X . . .
//1 1 1 1 1
//1 2 3 4 5
//0 0 3 7 12
//0 0 3 10 22
//0 0 3 13 35

//5 5 3 2
//0C0 1C0 2C0 3C0 4C0
//1C1 2C1 3C1 4C1 5C1
//2C2 3C2 4C2 5C2 6C2
//3C3 4C3 5C3 6C3 7C3
//3C1*5C2=3*10=30
//3C1*4C2+
//4C1*3C1+
//5C1*2C0 = 18+12+5=35
//これっぽいなあ
int main(){
  COMinit();
  ll H,W,A,B,MOD=1e9+7; cin>>H>>W>>A>>B;
  vector<ll> DP(W-B+1,0);
  ll x=H-A-1, xx=H-A-1+B,y=(A-1)+(W-B-1), ans=0;
  for(int i=0; i<W-B; i++) (DP[i]=COM(xx+i, x))%=MOD;
  for(int i=0; i<W-B; i++) (ans+=COM(y-i,W-B-1-i)*DP[i])%=MOD;
  cout<<ans<<endl;
}
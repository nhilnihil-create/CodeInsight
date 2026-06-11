#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> H;
//A2 B1として1e9/2回全探索、ぎりまにあう？
//最大値がどれかの探索でまいかい10^5だからむり
//降順sort、
//2番目との差
//おいついたら3番目との差
//おいついたら4番目･･･
//A3 B1
//100 80 70 40
//70 70 60 30
//50 60 50 20...

//グラフがあって、1個だけウエからA-B減らせる
//下からB全部へるって感じ
//priority_queueでだしてはいれて。カウントとる
//priorityがどんだけかかるかわかんない。間に合わないきがすんだよな
//ああ、だめそう
//2分探索?
//A3 B1
//100 80 70 40
//2番目に大きい値との差 20
//20/A=6+1=7
//2番目は80-7*B=73>0　NG
//3番目に大きい値との差30+10=40
//30/A+10/A=10+4=14
//3番目70-A*14=56>0
//4番目 60+40+30
//20+14+10=44
//40-44*B=-4<0
//44回おえた時点
//56 36 26 -4
//16 8 6 -4 //AでなくA-Bをひくのか

//100 80 70 40
//4番目 60+40+30
//30 20 15=65
//35 15 5 -25
//-25 -25 -25 -25
//いったん全部B引いて、A-Bを個別に判定、倒せるかどうか。
//攻撃回数で２分探索
bool beat(ll n, ll A, ll B, ll N){
  ll a=n;
  for(int i=0; i<N; i++){
    ll tmp=(H[i]-n*B);
    if(tmp<0) break;
    if(tmp%(A-B)>0) a--;
    tmp/=A-B;
    a-=tmp;
    if(a<0) return false;
  }
  return true;
}

int main(){
  ll N,A,B; cin>>N>>A>>B;
  ll ans=0, tmp;
  H.assign(N,0);
  for(int i=0; i<N; i++){
    ll h; cin>>h; H[i]=h;
  }
  sort(H.begin(), H.end(), greater<ll>());
  ll high=1e9, low=0, mid;
  while(high-low>1){
    mid=(high+low)/2;
    if(beat(mid,A,B,N))
      high=mid;
    else
      low=mid;
  }
  if(beat(low,A,B,N)) ans=low;
  else ans=high;
  cout<<ans<<endl;
}

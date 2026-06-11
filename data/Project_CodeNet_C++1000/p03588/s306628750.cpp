/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　|   _　 _l  
　 　　　／` ミ＿x ノ   Zzz..
　　 　 /　 　 　 |   コード見ちゃだめ！！
　　　 /　 ヽ　　  ﾉ
　 　 │　　|　|  |   
　／￣|　　 |　|  |
　| (￣ヽ＿_ヽ_)_ _)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) reverse((a).begin(),(a).end())
#define REP(i, n) for(int i = 0; i < n; i++)
const int MOD = 1e9+7;
typedef long long ll;
using Graph = vector<vector<int>>;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++) cin>>a[i]>>b[i];
  int amax=0;
  int now=0;
  for(int i=0;i<n;i++){
    if(amax<a[i]){
      amax=a[i];
      now=i;
    }
  }
  cout<<amax+b[now]<<endl;
}
#include <iostream>
#include <map>
#define rep(i, n) for(int i=0; i<n ;i++)
#define MOD 1000000007
using namespace std;

//2のn乗をMODで割った余りを返す
long long mod_2pow(int n){
  long long ans = 1;
  for(int i=0; i<n; i++)
    ans = (ans*2)%MOD;
  return ans;
}


int main(){
  int N;
  cin >> N;
  //firstがsecond回登場したことを表す
  map<int, int> m;
  int a;
  rep(i, N){
    cin >> a;
    m[a]++;
  }
  //ここまで入力

  //数え始める数字
  int s;
  
  //Nが偶数ならばa[i]は奇数になる
  //よって初めは1からスタート
  if(N%2 == 0)
    s = 1;
  //Nが奇数なら2からスタート
  else{
    //0の登場回数は1以外だと並び順が存在しない
    if(m[0] != 1){
      cout << 0 << endl;
      return 0;
    }
    s = 2;
  }

  //対称の人とペアになるはず
  for(; s<=N; s+=2)
    if(m[s] != 2){
      cout << 0 << endl;
      return 0;
    }

  cout << mod_2pow(N/2) << endl;

  return 0;
}

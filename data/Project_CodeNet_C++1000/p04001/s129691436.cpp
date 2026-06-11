#include<bits/stdc++.h>
using namespace std;
long long Sum = 0;
int N;
int *S;

//番号と合計と引数にした再帰関数
long long Shori(int pos, long long ParSum, long long cur){

  //終了：足す処理をする
  if(pos == N - 1){
    
    ParSum     += cur + S[pos];
    return Sum += ParSum;
  }
  
  //後ろに＋を入れる：Sumして、持ち越しを0にする
  Shori(pos + 1, ParSum + cur + S[pos], 0);
  //後ろに＋を入れない：Sumせずに配列の値を10倍にして持ち越し
  Shori(pos + 1, ParSum, (cur + S[pos]) * 10);
}

int main(){
  
  string _S;
  cin >> _S;
  N = _S.size();
  S = new int(N);
  
  for(int i = 0; i < N; i++) S[i] = _S[i] - '0';
  
  
  Shori(0, 0, 0);
  cout << Sum << endl;
  return 0;
}
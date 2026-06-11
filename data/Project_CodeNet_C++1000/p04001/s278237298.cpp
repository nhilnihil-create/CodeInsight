#include<bits/stdc++.h>
using namespace std;

using ll = long long ;

int main(){
  string s;
  cin >> s;
  int n = s.size() - 1; //＋記号を入れる場所の数
  ll sum = 0; //合計
  
  for(int bit =0; bit < (1 << n); bit++){
    ll t = s[0] - '0'; //charを数字に変換 足し算するまで，これを10倍してs[i＋1]を足していく
    
    for(int i =0; i <n; i++){
      if(bit & (1 << i)){ //+の記号があるとき
        sum += t;
        t = s[i+1] - '0';
      }
      else{ //記号がなかったとき
        t *= 10;
        t += s[i+1] - '0';
      }
    }
    sum += t; //ループが終わったら，sumに足していく
  }
   cout << sum << endl;
}
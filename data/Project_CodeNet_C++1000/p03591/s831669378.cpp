#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//string型文字列をint型整数にして返す
int str_to_num(string s) {return atoi(s.c_str());}
//約数の総数を返す
int count_divisor(int n){int c[n/2] = {1}; int n_half = n/2; for(int i=2;i<n_half;i++){if(n%i==0){n /= i;c[i]+=1;i--;if(n>1) continue;else break;}  }int r = 1;for(int i=2;i<n_half;i++){r *= c[i];}return r;}
//各桁の数の和を返す
int dig_num(int n){return (n<10) ? n: dig_num(n/10) + n%10;}

int main(){
  string s; cin >> s;
  bool flag = s.substr(0,4)=="YAKI";
  
  cout << (flag? "Yes\n":"No\n");
}
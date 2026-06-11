#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

// a*b mod p
ll mul_modp(ll a, ll b, ll p){return ((a % p) * (b % p)) % p;}
int main(){
  int N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;

  //https://atcoder.jp/contests/abc071/submissions/9321382
  ll ans;
  int init, is_yoko;
  if(S1[0]==S2[0]){ ans=3; init=1; is_yoko=0;}//0個目が縦置き
  else {ans=6; init=2; is_yoko=1;}//0個目が横置き
  const int MOD = 1000000007;

  for(int i=init; i<N; i++){
    if(S1[i] == S2[i]){//i個目が縦置き
      if(is_yoko) ans = mul_modp(ans, 1, MOD);//i-1個目が横置き
      else ans = mul_modp(ans, 2, MOD);
      is_yoko = 0;
    }
    else{//i個目が横置き
      if(is_yoko) ans = mul_modp(ans, 3, MOD);//i-1個目が横置き
      else ans = mul_modp(ans, 2, MOD);
      is_yoko = 1;
      i++;
    }
  }
  cout << ans << endl;
  // ll dp[2][53][3];//マス(i, j)を色kで塗る塗り方
  // for(int i=0; i<2; i++){
  //   for(int j=0; j<53; j++){
  //     for(int k=0; k<3; k++) dp[i][j][k] = 0;
  //   }
  // }
  // for(int k=0; k<3; k++) dp[0][0][k] = 1;
  
  // // for(int i=0; i<2; i++){
  //   // int h = (i+1)%2;
  //   for(int j=0; j<N; j++){
  //     for(int k=0; k<3; k++){
  //       int color1 = (k+1)%3;
  //       int color2 = (k+2)%3;
  //       if(S1[j] != S1[j+1]){//上の段が横向きに置かれていないなら塗る
  //         dp[0][j+1][color1] += dp[0][j][k];
  //         dp[0][j+1][color2] += dp[0][j][k];
  //       }
  //       else{
  //         dp[0][j+1][color1] = dp[0][j][k];
  //         dp[0][j+1][color2] = dp[0][j][k];
  //       }

  //       if(S1[j] != S2[j]){
  //         dp[1][j][color1] += dp[0][j][k];
  //         dp[1][j][color2] += dp[0][j][k];
  //       }
  //       else{
  //         dp[1][j][color1] = dp[0][j][k];
  //         dp[1][j][color2] = dp[0][j][k];
  //       }

  //       if(S2[j] != S2[j]){
  //       dp[1][j+1][color1] += dp[1][j][k];
  //       dp[1][j+1][color2] += dp[1][j][k];
  //       }
  //       // else{
  //       //   dp[1][j+1][color1] = dp[1][j][k];
  //       //   dp[1][j+1][color2] = dp[1][j][k];
  //       // }
  //     }
  //   }
  // // }
  // 
  // cout << dp[1][N-1][0]+dp[1][N-1][1]+dp[1][N-1][2] << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b) * b;
}
ll func2(ll n){
  ll res = 0;
  while(n%2 == 0){
    n /= 2;
    res++;
  }
  return res;
}

ll zyou(ll a,ll b){//a＾b
  ll res = 1;
  for(int i = 1;i<=b;i++){
    res *= a;
  }
  return res;
}
using Graph = vector<vector<char>>;

ll calc(ll a, ll b, ll p){//aのb乗をpで割った余り
  if(b == 0) return 1;

  else if(b%2 == 0){
    ll d = calc(a,b/2,p);
    return (d*d)%p;
  }
  else if(b%2 == 1){
    return (a * calc(a,b-1,p))%p;
  }
}

typedef pair<int,int> P;

bool is_prime(int n){//nが素数であるかどうか判定 iで割り切れると素数でない
    if(n == 1) return false;//1は例外
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}
int factorial(int a){
  int res = 1;
  while(a){
    res *= a;
    a--;
  }
  return res;
}
//各々のマスは一回のみ操作できる
//偶数枚のマスがmaxになるような操作を出力
//元々奇数のマス目のコインを、他の元々奇数のマス目に写す

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  /*同じ数字のカードが２枚以上あるものの枚数をカウントしつつ、
  奇数枚なら１枚に、偶数枚なら２枚にする 奇数枚のものをansにカウント
  */
 int c = 1;
 int even = 0;//偶数枚のものの数
 int odd = 0;//奇数枚 = 1枚のもの数
 int ans = 0;

 A.push_back(-1);
 rep(i,N){
   if(A[i] == A[i+1]) c++;
   else {
     if(c%2 == 0){
      even++;
      c = 1;
     }
     else if(c%2 == 1) {
      odd++;
      c = 1;
     }
   }
 }
 if(even%2 == 0){
   ans = even + odd;
 }
 else if(even%2 == 1){
   ans = even + odd -1;
 }
 cout << ans << endl;
}
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include<iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int N; cin >> N;
  int A[N];
  rep(i, N)cin >> A[i];
  map <int, int> num;
  rep(i, N){
    if (num.find(A[i]) == num.end()){
      num[A[i]] = 1;
    }
  }
  int ans = 0;
  int rest = 0;
  for (auto itr = num.begin(); itr != num.end(); itr++){
    ans ++;
  }
  if (ans % 2 == 0) ans-=1;
  cout << ans << endl;
}
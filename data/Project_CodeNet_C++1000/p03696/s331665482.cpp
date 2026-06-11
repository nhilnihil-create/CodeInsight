#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1e+9;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}



int rate[10];
int main() {
  int N;cin >> N;
  string s;cin >> s;
  int st=0;
  int l=0;
  rep(i,N) {
    if(s[i] == ')' && st == 0) l++;
    else if(s[i] == '(') st++;
    else if(s[i] == ')') st--;
  }
  rep(i,l) cout << '(';
  rep(i,N) cout << s[i];
  rep(i,st) cout << ')';
  cout << endl;
  
  return 0;
}

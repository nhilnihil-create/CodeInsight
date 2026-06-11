#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define dupl(s) s.erase(unique(s.begin(), s.end()), s.end());//重複取り除き
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  if (a > b) cout << 0;
  else if (n == 1){
    if (a != b) cout << 0;
    else cout << 1;
  }
  else cout << (b * (n - 1) + a) - (a * (n - 1) + b) + 1;
}
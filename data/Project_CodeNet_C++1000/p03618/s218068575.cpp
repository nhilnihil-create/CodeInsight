#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  string S;
  cin >> S;

  long long n = S.size();
  vector<long long> num(26);
  for(int i = 0;i < n;i++) {
    char ch = S.at(i);
    num.at(ch-'a')++;
  }

  long long ans = n*(n-1)/2;
  for(int i = 0;i < 26;i++) {
    long long N = num.at(i);
    ans -= N*(N-1)/2;
  }

  cout << ans+1 << endl;
  

}

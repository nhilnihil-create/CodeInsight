#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

// アルファベット小文字
vector<char> alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
  string s;
  int K;
  cin >> s >> K;
  int N = s.size();
  for (int i=0; i<N; i++) {
    if (('z'-s[i])+1<=K&&s[i]!='a') {
      K -= ('z'-s[i])+1;
      s[i] = 'a';
    }
    if (i==N-1) {
      K %= 26;
      for (int j=0; j<K; j++) {
        if (s[i]=='z') s[i] = 'a';
        else s[i]++;
      }
    }
  }
  cout << s << endl;
  return 0;
}
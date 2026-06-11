#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

ll vatical[1010];
ll horizontal[1010];

int main(){
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  for(int i = 0;i < N;i++){
    int n = S[i] - 'a';
    if(i == N-1){
      S[i] = 'a' + (n+K) % 26;
      break;
    }
    if(S[i] == 'a') continue;
    if(K >= 26 - n){
      S[i] = 'a';
      K -= (26-n);
    }else{
      continue;
    }
  }
  cout << S << endl;
}

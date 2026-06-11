#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  string S, T;
  std::cin >> S;
  std::cin >> T;
  int Q, a, b, c, d;
  std::cin >> Q;
  std::vector<int> s(S.size()+1, 0), t(T.size()+1, 0);
  for(int i=0;i<S.size();i++) s[i+1] = s[i] + (S[i]=='A'?1:2);
  for(int i=0;i<T.size();i++) t[i+1] = t[i] + (T[i]=='A'?1:2);
  for(int q=0;q<Q;q++){
    std::cin >> a >> b >> c >> d;
    //std::cout << s[b] << " " << s[a-1] << " " << t[d] << " " << t[c-1] << '\n';
    if((s[b]-s[a-1])%3==(t[d]-t[c-1])%3) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
  }
  return 0;
}

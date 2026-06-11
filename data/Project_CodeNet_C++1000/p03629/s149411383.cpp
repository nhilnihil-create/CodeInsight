#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  string S;
  std::cin >> S;
  std::vector<int> las(S.size());
  std::vector<int> alpha(26, 0);
  int c=0, cycle=0;
  for(int i=S.size()-1;i>=0;i--){
    if(alpha[S[i]-'a']==0) c++;
    alpha[S[i]-'a']++;
    las[i] = cycle;
    if(c==26) {
      cycle++, c = 0;
      for(int j=0;j<26;j++) alpha[j] = 0;
    }
  }
  string ans = "";
  int now = 0;
  bool flag = true;
  while(true){
    if(las[now]==0){
      map<int, int> t;
      int k = 0;
      for(int i=now;i<S.size();i++) if(t.find(S[i]-'a')==t.end()) k++,t.emplace(S[i]-'a', i);
      if(k==26) ans += 'a', now = t.at(0)+1;
      flag = false;
    }
    if(!flag) break;
    for(int j=0;j<26;j++) alpha[j] = 0;
    c=0;
    multiset<std::vector<int>> mp;
    while(true){
      if(alpha[S[now]-'a']==0) {
        c++;
        mp.insert(std::vector<int> {las[now], S[now]-'a', now});
        alpha[S[now]-'a']=1;
      }
      if(c==26) break;
      now++;
    }
    std::vector<int> tmp = *mp.begin();
    ans += (tmp[1]+'a');
    now = (tmp[2]+1);
    //std::cout << now << '\n';
  }
  //for(int i=0;i<S.size();i++) std::cout <<S[i] << " " << las[i] << " " << i<< endl;
  // last_one
  //-------------------------------------------------------------------
  //std::cout << now << '\n';
  set<int> ls;
  for(int i=0;i<26;i++) ls.insert(i);
  for(int i=now;i<S.size();i++) if(ls.find(S[i]-'a')!=ls.end()) ls.erase(S[i]-'a');
  ans += (*ls.begin() + 'a');
  //-------------------------------------------------------------------
  std::cout << ans << '\n';
  return 0;
}

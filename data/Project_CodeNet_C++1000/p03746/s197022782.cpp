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

struct node{
  int num;
  std::vector<int> child;
};
int main(int argc, char const *argv[]) {
  int N, M, a, b;
  std::cin >> N >> M;
  std::vector<node> nd(N+1);
  std::vector<bool> checked(N+1, false);
  for(int i=1;i<=N;i++) nd[i].num = i;
  for(int i=0;i<M;i++){
    std::cin >> a >> b;
    nd[a].child.push_back(b);
    nd[b].child.push_back(a);
  }
  int now = 1;
  bool flag = true;
  checked[now] = true;
  std::vector<int> ans;
  while(flag){
    ans.push_back(now);
    for(int i=0;i<nd[now].child.size();i++){
      if(checked[nd[now].child[i]]==false){
        now = nd[now].child[i];
        checked[now] = true;
        break;
      }else if(i==nd[now].child.size()-1){
        flag = false;
      }
    }
  }
  flag = true;
  std::vector<int> ans_pre;
  now = 1;
  while(flag){
    ans_pre.push_back(now);
    for(int i=0;i<nd[now].child.size();i++){
      if(checked[nd[now].child[i]]==false){
        now = nd[now].child[i];
        checked[now] = true;
        break;
      }else if(i==nd[now].child.size()-1){
        flag = false;
      }
    }
  }
  std::cout << ans.size() + ans_pre.size() - 1 << '\n';
  for(int i=ans_pre.size()-1;i>0;i--) std::cout << ans_pre[i] << " ";
  for(int i=0;i<ans.size();i++) std::cout << ans[i] << (i==ans.size()-1?"\n":" ");
  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <set>
#include <map>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, majo=0, mino = 1000000, majo_count=0, mino_count=0;
  std::cin >> N;
  std::vector<ll> a(N);
  for(int i=0;i<N;i++){
    std::cin >> a[i];
    majo = max(majo, a[i]);
    mino = min(mino, a[i]);
  }
  //majo - mino >= 2
  if(majo-mino>=2){
    std::cout << "No" << '\n';
    return 0;
  }
  for(int i=0;i<N;i++){
    if(a[i]==majo) majo_count++;
    if(a[i]==mino) mino_count++;
  }
  //majo == mino
  if(majo==mino) std::cout << (majo*2<=N||majo==N-1?"Yes":"No") << '\n';
  // majo - mino = 1
  else if(((majo-(mino_count))*2<=N-mino_count||majo==N-1-mino_count)&&mino>=mino_count){
    std::cout << "Yes" << '\n';
  }else{
    std::cout << "No" << '\n';
  }
  return 0;
}

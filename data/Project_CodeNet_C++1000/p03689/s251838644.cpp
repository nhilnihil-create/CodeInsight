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
  int H, W, h, w;
  std::cin >> H >> W >> h >> w;
  if(H%h==0&&W%w==0){
    std::cout << "No" << '\n';
    return 0;
  }
  std::cout << "Yes" << '\n';
  if(W%w!=0){
    std::vector<int> S(W+1);
    for(int i=0;i<w;i++) S[i] = 0;
    S[0] = 0;
    S[W%w] = 1000007;
    for(int i=0;i<w;i++) for(int j=i+w;j<=W;j+=w) S[j] = S[j-w] - 1;
    for(int j=0;j<H;j++) for(int i=1;i<=W;i++) std::cout << S[i] - S[i-1]<< (i==W?"\n":" ");
  }else{
    std::vector<int> S(H+1);
    for(int i=0;i<h;i++) S[i] = 0;
    S[0] = 0;
    S[H%h] = 1000007;
    for(int i=0;i<h;i++) for(int j=i+h;j<=H;j+=h) S[j] = S[j-h] - 1;
    for(int i=1;i<=H;i++) for(int j=0;j<W;j++) std::cout << S[i] - S[i-1]<< (j==W-1?"\n":" ");
  }
  return 0;
}

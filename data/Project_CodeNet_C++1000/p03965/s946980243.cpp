#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  string S; cin >> S;
  int ssize = (int)S.size();
  int gtime = 0;
  int ptime = 0;
  int win = 0;
  int lose = 0;
  rep(i,ssize){
    char tophand = S[i];
    if(tophand == 'g'){
      if(ptime < gtime){
        ptime++;
        win++;
      }
      else{
        gtime++;
      }
    }
    else{ // 'p'
      if(ptime < gtime){
        ptime++;
      }
      else{
        gtime++;
        lose++;
      }
    }
  }
  cout << win - lose << endl;
  return 0;
}

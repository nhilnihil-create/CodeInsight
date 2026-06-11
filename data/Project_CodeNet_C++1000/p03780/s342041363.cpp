#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

LL mod = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N,K;
  cin >> N >> K;

  vector<LL> v(N);

  REP(i,N){
    cin >> v[i];
  }

  BACKSORT(v);

  vector<bool> KKK(K + 1, false);

  KKK[0] = true;

  set<LL> fuhituyou;

  REP(i,N){
    fuhituyou.insert(v[i]);
    REP(kk,K){
      LL j = K - kk-1;
      if (KKK[j])
      {
        if(j+v[i]>=K){
          //hituyou
          fuhituyou.erase(v[i]);
        }
        else
        {
          KKK[j + v[i]] = true;
        }
      }
    }
  }

  LL cnt = 0;

  SORT(v);

  v.push_back(-1);

  REP(i,N+1){
    if(fuhituyou.count(v[i])==0){
      cout << i << endl;
      break;
    }
    if(v[i]==-1){
      cout << i << endl;
      break;
    }
  }
}

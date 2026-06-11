#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N,M;
int d[100100];

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N>>M;

  int a,b;
  while (M --> 0) cin>>a>>b, d[a]++,d[b]++;

  bool good=1;
  for (int i=1;i<=N;i++) if (d[i]&1) {
      good=0;break;
    }

  cout << (good ? "YES\n" : "NO\n");

  return 0;
}

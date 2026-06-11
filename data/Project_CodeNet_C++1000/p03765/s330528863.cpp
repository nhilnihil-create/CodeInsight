#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

using namespace std;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  string s,t;
  cin>>s>>t;
  int cum_s[100001]={},cum_t[100001]={};

  cum_s[0]=(s[0]=='A'?1:2);
  cum_t[0]=(t[0]=='A'?1:2);
  for(int i=1;i<s.size();i++){
    cum_s[i]=cum_s[i-1]+(s[i]=='A'?1:2);
  }
  for(int i=1;i<t.size();i++){
    cum_t[i]=cum_t[i-1]+(t[i]=='A'?1:2);
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;

    int sv=(a-1>=0?(cum_s[b]-cum_s[a-1]):cum_s[b]);
    int st=(c-1>=0?(cum_t[d]-cum_t[c-1]):cum_t[d]);
    cout<<((sv%3==st%3)?"YES":"NO")<<endl;
  }

  return 0;
}

    #include <set>
    #include <map>
    #include <list>
    #include <queue>
    #include <stack>
    #include <cmath>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <string>
    #include <bitset>
    #include <cctype>
    #include <cstdlib>
    #include <cstring>
    #include <utility>
    #include <numeric>
    #include <complex>
    #include <sstream>
    #include <fstream>
    #include <iomanip>
    #include <cassert>
    #include <iostream>
    #include <iterator>
    #include <algorithm>
    using namespace std;
    typedef long long ll;
    typedef vector<int> vint;
    typedef pair<int, int> pint;
    #define rep(i, n) REP(i, 0, n)
    #define all(v) v.begin(), v.end()
    #define REP(i, x, n) for(int i = x; i < n; i++)
    #define INF 2e9
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,d,x,flag=0,count=0;
  string s,s2;
  s="YAKI";
  cin>>s2;
  a=s2.size();
  rep(i,4){
    if(s2[i]!=s[i]){
      flag=1;
      break;
    }
  }
  if(flag==0 && a>=4){
    cout<<"Yes"<<'\n';
  }
  else{
    cout<<"No"<<'\n';
  }
  return(0);
}

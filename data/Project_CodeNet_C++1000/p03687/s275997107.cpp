#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string t; cin >> t;
  set<char> S;
  rep(i,t.size()) S.insert(t[i]);

  int retval = 1000;
  for (auto s:S){
    vector<int> a;
    int cnt = 0;
    rep(i,t.size()){
      if (t[i]!=s) cnt++;
      else {
        a.push_back(cnt);
        cnt = 0;
      }

      if (i==t.size()-1 && cnt>0) a.push_back(cnt);
    }
    retval = min(*max_element(all(a)), retval);
  }
  cout << retval << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}


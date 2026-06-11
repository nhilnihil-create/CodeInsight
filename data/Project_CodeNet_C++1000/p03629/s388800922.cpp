#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;
typedef vector<unordered_map<lli,lli>> graph;

typedef tuple<lli,char,lli> con;

string a;
queue<con> q;
vector<con> mem;
vector<con> ans;
set<lli> used;


int main(){
  cin >> a;
  q.push(make_tuple(-1,0,-1));
  while(!q.empty()){
    con c = q.front();
    lli point = get<0>(q.front());
    char chr = get<1>(q.front());
    lli prev = get<2>(q.front());
    q.pop();
    if(used.count(point) != 0) continue;
    used.insert(point);
    mem.push_back(c);
    if(point == (lli)a.size()){
      for(lli i = mem.size()-1;i >= 0;){
        ans.push_back(mem[i]);
        i = get<2>(mem[i]);
      }
      for(lli i = ans.size()-2;i >= 0;i--){
        cout << get<1>(ans[i]);
      }
      cout << endl;
      return 0;
    }
    for(char c = 'a';c <= 'z';c++){
      lli p = a.size();
      for(lli i = point+1;i < a.size();i++){
        if(a[i] == c){
          p = i;
          break;
        }
      }
      if(used.count(p) == 0) q.push(make_tuple(p,c,mem.size()-1));
    }

  }
  return 0;
}

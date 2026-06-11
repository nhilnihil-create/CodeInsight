
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
void print_pair(pi a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<int T1, int T2>
void print_2d(int a[T1][T2], int x, int y){
  For(i, x){
    For(j, y){
      cerr<<a[i][j]<<" ";
    }
    cerr<<endl;
  }
}

string in;
vector<vector<pi>> alphabet;

vector<pi> initialize(){
  vector<pi> ret(26);
  REP(26){
    ret[i].first=in.size();
    ret[i].second=-1;
  }
  return ret;
}

int main(){
  cin>>in;
  cerr<<in;
  int cnt=0,full=0;
  vector<pi> workspace=initialize();
  Rev(i,in.size()){
    size_t index=in[i]-'a';
    workspace[index].first=min(workspace[index].first,i);
    workspace[index].second=max(workspace[index].second,i);
    print_pair(workspace[index]);
    cerr<<endl;
    if(workspace[index].second==i){
      cnt++;
      if(cnt>=26){
        cnt=0;
        cerr<<"cnt is full at "<<i<<endl;
        alphabet.push_back(workspace);
        workspace=initialize();
      }
    }
  }
  char tmp;
  For(i,workspace.size()){
    print_pair(workspace[i]);
    if(workspace[i].second==-1){
      tmp='a'+i;
      break;
    }
  }
  string ans="";
  ans+=tmp;
  while(alphabet.empty()!=true){
    workspace=alphabet.back();alphabet.pop_back();
    int t=ans.back()-'a';
    int e=workspace[t].first;
    char b;
    For(i,workspace.size()){
      if(workspace[i].second<=e){
        b='a'+i;
        break;
      }
    }
    ans+=b;
  }
  cout<<ans<<endl;
  return 0;
}

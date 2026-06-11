#include <iostream>
#include <map>
using namespace std;
int main(){
  int dx[] = {1,0,-1,0,1,1,-1,-1}, dy[] = {0,1,0,-1,1,-1,1,-1};
  int H, W, N;
  cin >> H >> W >> N;
  int a, b;
  map<pair<int,int>, int> M;
  for(int i = 0; i < N; ++i){
    cin >> a >> b;
    if(a > 1 && a < H && b > 1 && b < W){
      ++M[make_pair(a,b)];
    }
    for(int j = 0; j < 8; ++j){
      int s = a + dx[j], t = b + dy[j];
      if(s > 1 && s < H && t > 1 && t < W){
	++M[make_pair(s,t)];
      }
    }
  }
  long long int ans[10], t = (long long int)(H-2)*(W-2);
  fill(ans,ans+10,0LL);
  for(map<pair<int,int>, int>::iterator itr = M.begin(); itr != M.end(); ++itr){
    ++ans[itr->second];
    --t;
    //cout << itr->first.first << ", " << itr->first.second << " = " << itr->second << endl;
  }
  ans[0] = t;
  for(int i = 0; i < 10; ++i){
    cout << ans[i] << endl;
  }
  return 0;
}

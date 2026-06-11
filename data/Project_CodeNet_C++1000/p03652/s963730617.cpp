#include<bits/stdc++.h>
using namespace std;

#define int long long

const long long inf = 1e18;

int solve(vector<deque<int>> &A){
  int N = A.size(), M = A[0].size();
  int res = N;
  vector<int> del(M);

  while(true){
    vector<pair<int,int>> con(M+1);

    con[M] = {-1, M};
    for(int i = 0; i < M; i++){
      con[i].second = i;
    }

    for(int i = 0; i < N; i++){
      // cout<<"<> "<<i<<" "<<A[i].front()<<" size "<<A[i].size()<<endl;
      while(true){
        if(A[i].size() == 0) return res;
        if(del[A[i].front()] == true) {
          A[i].pop_front();
        } else break;
      }

      // cout<<"<> "<<i<<" "<<A[i].front()<<endl;
      con[A[i].front()].first++;
    }

    //string hogehoge; cin>>hogehoge;
    sort(con.begin(), con.end(), greater<pair<int,int>>());
    res = min(res, con.front().first);

    //cout<<"res "<<res<<" con "<<con.front().first<<" size "<<A[0].size()<<endl;

    for(int i = 0; i < M; i++){
      // cout<<"i = "<<i<<" con "<<con[i].first<<" "<<con[i].second<<endl;
      del[con[i].second] = true;
      if(con[i].first != con[i+1].first) break;
    }
  }

  return res;
}

signed main(){

  vector<deque<int>> A;
  int N, M;

  cin>>N>>M;

  A.resize(N, deque<int>(M));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin>>A[i][j];
      A[i][j]--;
    }
  }

  cout<<solve(A)<<endl;

  return 0;
}

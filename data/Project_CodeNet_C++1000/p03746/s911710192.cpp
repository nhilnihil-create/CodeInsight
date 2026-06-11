#include <bits/stdc++.h>
using namespace std;


vector<int> graph[100010] = {};
bool used[100010] = {};

int main(){
  int n, m;
  cin >> n >> m;

  int a, b;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  stack<int> st;
  st.push(1);

  int num = 1;
  used[1] = true;
  while(1){
    int old = st.size();
    for(int i = 0;i < graph[num].size();i++){
      if(used[graph[num][i]] == false){
        st.push(graph[num][i]);
        num = graph[num][i];
        used[num] = true;
        break;
      }
    }
    if(old == st.size()){
      break;
    }
  }

  queue<int> que;

  while(!st.empty()){
    que.push(st.top());
    st.pop();
  }

  num = 1;
  while(1){
    int old = que.size();
    for(int i = 0;i < graph[num].size();i++){
      if(used[graph[num][i]] == false){
        que.push(graph[num][i]);
        num = graph[num][i];
        used[num] = true;
        break;
      }
    }
    if(old == que.size()){
      break;
    }
  }

  cout << que.size() << endl;
  while(!que.empty()){
    cout << que.front();
    que.pop();
    if(!que.empty()){
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}

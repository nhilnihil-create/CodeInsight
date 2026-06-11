#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF ((int)1e17)
#define MAX 110000

int N, K;
int a[MAX], hoge[MAX], fuga[MAX];
vector<int> node[MAX];


signed main(){
  int ans = 0, temp = 0;
  stack<pair<int,pair<int,int> > > st;

  cin>>N>>K;

  for(int i = 0; i < N; i++){
    hoge[i] = -1;
  }

  for(int i = 0; i < N; i++){
    cin>>a[i];
    a[i]--;
    if(i) node[a[i]].push_back(i);
  }

  st.push(make_pair(0,make_pair(0,0)));

  while(!st.empty()){
    pair<int,pair<int,int> > p = st.top(), t; st.pop(); 
    int num = p.first;

    if(p.second.second >= node[num].size()){      
      if(num == 0) break;
      else {
	t = st.top(); st.pop();
	if(p.second.first+1 == K && a[num]){
	  ans++;
	  p.second.first = -1;
	}
	t.second.first = max(t.second.first,p.second.first+1);
      }
      st.push(t);
    } else {
      st.push(make_pair(num,make_pair(p.second.first,p.second.second+1)));
      st.push(make_pair(node[num][p.second.second],make_pair(0,0)));
    }

  }

  if(a[0] != 0) ans++;

  
  cout<<ans<<endl;

  

  return 0;
}

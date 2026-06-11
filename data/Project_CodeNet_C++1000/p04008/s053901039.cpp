#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct p{
  int num;
  int d;
  bool operator<(const struct p & right) const {
    return d<right.d;
  }
};


struct bf{
  int ne;
  int f;
};
//
// int search(int num){
//   int a=0;
//   for(auto itr=child[num].begin();itr!=child[num].end();itr++){
//     searched[(*itr)]=true;
//     a=max(a,search(*itr)+1);
//   }
//   return a;
// }

int main(){
  int n,k,ans=0;
  cin >> n >> k;
  vector<int> a(n);
  vector<list<int>> child=vector<list<int>>(n,list<int>());
  vector<bool> searched=vector<bool>(n,false),searchedr=vector<bool>(n,false);
  for(int i=0;i<n;i++){
    cin >> a[i];
    a[i]--;
    if(i!=0) child[a[i]].push_back(i);
  }

  vector<int> dep(n,1);
  dep[0]=0;
  queue<struct p> bfs;
  priority_queue<struct p> q;
  struct p now;
  if(k==1){
    for(int i=0;i<n;i++){
      if(a[i]!=0) ans++;
    }
  }else{
    if(a[0]!=0) ans++;
    bfs.push({0,0});
    while(!bfs.empty()){
      now=bfs.front();
      bfs.pop();
      searched[now.num]=true;
      for(auto itr=child[now.num].begin();itr!=child[now.num].end();itr++){
        // dep[*itr]=now.d+1;
        bfs.push({*itr,now.d+1});
        q.push({*itr,now.d+1});
      }
    }
    while(!q.empty()){
      now=q.top();
      q.pop();
      if(dep[now.num]==k){
        if(a[now.num]) ans++;
      }else{
        dep[a[now.num]]=max(dep[a[now.num]],dep[now.num]+1);
      }
    }
    // int lst,ne;
    // for(int i=0;i<n;i++){
    //   if(!searched[i]){
    //     bfs.push({i,0});
    //     while(!bfs.empty()){
    //       now=bfs.front();
    //       bfs.pop();
    //       searchedr[now.num]=true;
    //       for(auto itr=child[now.num].begin();itr!=child[now.num].end();itr++){
    //         // dep[*itr]=now.d+1;
    //         if(searchedr[*itr]){
    //           lst=(*itr);
    //           while(!bfs.empty()) bfs.pop();
    //           break;
    //         }else{
    //           bfs.push({*itr,0});
    //         }
    //       }
    //     }
    //     list<int> loop;
    //     list<int> lc;
    //     loop.push_back(lst);
    //     lc.push_front(lst);
    //     for(ne=a[lst];ne!=i;ne=a[ne]){
    //       loop.push_back(ne);
    //       lc.push_front(ne);
    //     }
    //     for(auto itr=loop.begin(),itrc=lc.begin();itr!=loop.end();itr++,itrc++){
    //       bfs.push({(*itr),0});
    //       while(!bfs.empty()){
    //         now=bfs.front();
    //         bfs.pop();
    //         searched[now.num]=true;
    //         for(auto itr2=child[now.num].begin();itr2!=child[now.num].end();itr2++){
    //           // dep[*itr]=now.d+1;
    //           if((*itr2)!=(*itrc)){
    //             bfs.push({*itr2,now.d+1});
    //             q.push({*itr2,now.d+1});
    //           }
    //         }
    //       }
    //       while(!q.empty()){
    //         now=q.top();
    //         q.pop();
    //         if(dep[now.num]==k){
    //           ans++;
    //         }else{
    //           dep[a[now.num]]=max(dep[a[now.num]],dep[now.num]+1);
    //         }
    //       }
    //     }
    //
    //   }
    // }
  }
  cout << ans << endl;
  return 0;
}

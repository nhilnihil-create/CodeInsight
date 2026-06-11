#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>

struct Interval{
  int right;
  int val;
  Interval(int right,int val):right(right),val(val){
  }
  bool operator<(struct Interval other)const{
    return right>other.right;
  }
};


int xs[501];
int ans[500*500+1];
std::vector<struct Interval> here[500*500+1];

void fail(){
  printf("No\n");
  exit(0);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&xs[i]);
    for(int k=1;k<i;k++){
      here[1].emplace_back(xs[i]-1,i);
    }
    here[xs[i]].emplace_back(xs[i],i);
    for(int k=i+1;k<=N;k++){
      here[xs[i]+1].emplace_back(N*N,i);
    }
  }
  std::priority_queue<struct Interval> active;
  for(int i=1;i<=N*N;i++){
    for(auto add:here[i]){
      active.push(add);
    }
    if(active.empty()) fail();
    if(active.top().right<i) fail();
    ans[i]=active.top().val;
    active.pop();
  }
  printf("Yes\n");
  for(int i=1;i<=N*N;i++){
    if(i>1) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}

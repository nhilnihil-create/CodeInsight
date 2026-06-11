#include <cstdio>

int as[100005];
int N;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int solve(){
  int odd=0;
  int last=0;
  for(int i=0;i<N;i++){
    if(as[i]&1){
      odd++;
      last=i;
    }
  }
  if(N%2==0&&odd%2==0) return 0;
  if(N%2==0&&odd%2==1) return 1;
  if(N%2==1&&odd%2==0) return 1;
  if(as[last]==1) return 0;
  as[last]--;
  int g=0;
  for(int i=0;i<N;i++){
    g=gcd(g,as[i]);
  }
  for(int i=0;i<N;i++){
    as[i]/=g;
  }
  return !solve();
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(solve()){
    printf("First\n");
  }else{
    printf("Second\n");
  }
  return 0;
}

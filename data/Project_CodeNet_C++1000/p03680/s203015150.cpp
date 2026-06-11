#include <iostream>
 
using namespace std;
 
int main(){
  int N;
  cin >> N;
  int a[N], mem[N], flg=0, p=0, count=1;

  for(int i=0; i<N; i++){
    cin >> a[i];
    mem[i]=0;
    if(a[i]==2){
      flg=1;
    }
  }

  if(flg==0){
    printf("-1\n");
  }else{
    while(mem[p]==0 && a[p] != 2){
      mem[p]=1;
      p = a[p]-1;
      count++;
    }
    if(a[p]==2){
      printf("%d\n",count);
    }else{
      printf("-1\n");
    }
  }
}

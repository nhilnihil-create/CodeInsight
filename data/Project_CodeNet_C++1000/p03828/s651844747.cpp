#include <stdio.h>
#include <math.h>
#define MAX 1000
#define LENGTH 168

typedef struct {
  int prime;
  int cnt;
} Number;

int main(void)
{
  int i, j;
  int k = 0;
  int p[MAX];
  int N_0;
  Number q[LENGTH];
  long long n = 1;
  long long m = 7+pow(10,9);

  //---初期化---
  for(i=0 ; i<MAX ; i++) {
      p[i] = 0;
      p[0] = 1;
  }

  for (i=0;i<LENGTH;i++){
      q[i].cnt = 1;
      q[i].prime = 0;
  }


  //---倍数を除外---
  for(i=2 ; i<=MAX/2 ; i++){
    for(j=2 ; i*j<=MAX ; j++){
      if(p[i*j-1] == 0){
          p[i*j-1] = 1;
      }
    }
  }
  for(i=0 ; i<MAX ; i++){
    if(p[i] == 0){
        q[k].prime = i+1;
        //printf("%d\n", q[k].prime);
        k++;
    }

  }

//   for(int test = 0; test < 168; test++){
//       printf("%d\n", q[test]);
//   }

  //ここから一つずつの素数をカウント

  scanf("%d",&N_0);

  for(i = 1; i <= N_0; i++){
      for(j = 0; j < LENGTH; j++){
          if(q[j].prime <= i){
              int k = i;
              while(k%q[j].prime == 0){
                  q[j].cnt++;
                  k = k/q[j].prime;
                  //printf("%d\n",k);
              }
          }
      }
  }

  for(i = 0; i < LENGTH; i++){
      //printf("%d -> %d\n",q[i].prime,q[i].cnt);
      n = n * q[i].cnt;
      if(n > m){
          n = n % m;
      }
  }

  printf("%d\n",n);

  return 0;
}
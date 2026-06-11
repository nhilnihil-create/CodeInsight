#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define F first
#define S second
using namespace std;
int n,m;
int x[111111];
int a[111111];
int main(void){
  scanf("%d%d",&n,&m);
  for(int i = 0; i < n; i++){
    scanf("%d",x+i);
    a[x[i]]++;
  }


  int sum = 0;
  for(int i = 1; i*2 <= m; i++){
    int ag = 0;
    int ak = 0;
    int bg = 0;
    int bk = 0;
    int b = (m-i);
    //if(b==i) b += m;
    for(int j = 0; i+m*j < 111111;  j++){
      ag += a[i+m*j]/2;
      ak += a[i+m*j]%2;
    }
    for(int j = 0; b+m*j < 111111;  j++){
      bg += a[b+m*j]/2;
      bk += a[b+m*j]%2;
    }
    /*
    printf("a %d b %d\n",i,b);
    printf("ak %d bk %d\n",ak,bk);
    printf("ag %d bg %d\n",ag,bg);
    */

    if(i != b){
      int mk = min(ak,bk);
      sum += mk;
      if(ak > bk){
	bk -= mk;
	ak -= mk;
	int kk = min(ak/2,bg);
	sum += kk*2;
	ak -= kk*2;
	bg -= kk;
      }
      if(ak < bk){
	ak -= mk;
	bk -= mk;
	int kk = min(bk/2,ag);
	sum += kk*2;
	bk -= kk*2;
	ag -= kk;
      }
      sum += ag+bg;
      //qprintf("sum %d\n",sum);
    }else{
      sum += ak/2 + ag;
      //printf("sum %d\n",sum);
    }
  }
  int ggg = 0;
  int kkk = 0;
  for(int i = 1; m*i < 111111; i++){
    ggg += a[m*i]/2;
    kkk += a[m*i]%2;
  }
  sum += kkk/2 + ggg;


  printf("%d\n",sum);
}

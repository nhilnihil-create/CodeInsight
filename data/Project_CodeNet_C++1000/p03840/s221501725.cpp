#include <cstdio>
#include <algorithm>
#include <stdint.h>

int main(){
  int64_t I,O,T,J,L,S,Z;
  scanf("%ld %ld %ld %ld %ld %ld %ld",&I,&O,&T,&J,&L,&S,&Z);
  int64_t best=(I/2+L/2+J/2)*2;
  if(I&&L&&J){
    best=std::max(best,3+((I-1)/2+(L-1)/2+(J-1)/2)*2);
  }
  printf("%ld\n",best+O);
  return 0;
}

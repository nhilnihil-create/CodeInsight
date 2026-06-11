#include<iostream>
 
using namespace std;
 
int main(){
  long long a, b, x;
  cin >> a >> b >> x;
  long long a_min=a, b_max=b, ans;
 
  if(a==b){
    if(a_min%x!=0){
      printf("0\n");
    }else{
      printf("1\n");
    }
  }else{
    while(a_min%x!=0){
      long long t = a_min % x;
      a_min += (x - t);
    }
    while(b_max%x!=0){
      long long t = b_max % x;
      b_max -= t;
    }
    if(a_min==b_max){
      if(a_min%x!=0){
        printf("0\n");
      }else{
        printf("1\n");
      }
    }else if(a_min > b_max){
      printf("0\n");
    }else{
      ans = (b_max - a_min - 1 )/ x;
      printf("%llu\n", ans + 2);
    }    
  }
}

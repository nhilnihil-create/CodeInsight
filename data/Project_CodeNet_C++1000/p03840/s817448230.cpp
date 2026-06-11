#include<iostream>
using namespace std;
#define df 0
#define f(a) ((a)/2*2)

int main(){
  if(df) printf("*debug mode*\n");
  long int I, O, T, J, L, S, Z ; cin >>I >>O >>T >>J >>L >>S >>Z; 
  long int s=O;
  s+=f(I)+f(J)+f(L);
  long int s1=O+3;
  if(I && J && L){
    I--;J--;L--;
    s1+=f(I)+f(J)+f(L);
  }else s1=s;
  printf("%ld",max(s,s1));
}

/// confirm df==0 ///

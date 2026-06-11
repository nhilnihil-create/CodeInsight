#include <iostream>

using namespace std;


int P[100001];
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;++i){
    cin >> P[i];
  }
  P[N] = -1;
  bool cont=false;
  int swp_num = 0 , len = 0;
  for(int i=0;i<N+1;++i){
    if(cont){
      if(P[i]!=i+1){
        swp_num+=len/2+1;
        len = 0;
        cont=false;
      }else{
        len++;
      }
    }else if(P[i]==i+1){
      cont = true;
      len = 0;
    }
  }
  cout << swp_num << endl;
  return 0;
}
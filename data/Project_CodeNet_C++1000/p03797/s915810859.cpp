 #include <iostream>
 #include <math.h>
using namespace std;
int main() {
  long N, M,ans;
  cin >> N >> M ;
  long tmp1,tmp2;
  if((M- N*2)<0){
    ans=M/2;
  }else{
  tmp1 = N;
  tmp2 = (M - N*2)/4;
  ans = tmp1 + tmp2;
  }
  std::cout << ans;
}
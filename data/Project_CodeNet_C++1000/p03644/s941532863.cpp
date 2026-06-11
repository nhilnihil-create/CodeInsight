#include <iostream>
#include <string>
using namespace std;
 
/*int main() {
  int N;
  cin >> N;
  int max=0;
  int tsk=1;
  for(int i = 0;i<N;i++){
    int res=0;
    while(true){
      if(i%N==0) ++res;
      else break;
      i/=2;
    }
    if(max < res){
      max = res;
      tsk=i;
    }
  }
  cout << tsk << endl;
}*/

int main(){
  int N;
  cin >> N;
  if(N >= 64) cout << 64 << endl;
  else if(N >= 32) cout << 32 << endl;
  else if(N >= 16) cout << 16 << endl;
  else if(N >=  8) cout << 8 << endl;
  else if(N >= 4) cout << 4 << endl;
  else if(N >= 2) cout << 2 << endl;
  else  cout << 1 << endl;

}
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int max=0;
  int tsk=1;
  for(int i = 0;i<=N;++i){
    int res=0;
    int kari=i;
    while(true){
        if(kari!=0){
            if(kari%2==0) ++res;
            else break;
        }
        else{
            break;
        }
        kari /= 2;
    }
    if(max < res){
      max = res;
      tsk=i;
    }
  }
  cout << tsk << endl;
}
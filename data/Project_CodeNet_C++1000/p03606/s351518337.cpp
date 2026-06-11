#include <bits/stdc++.h>
using namespace std;

int main() {
  int result=0;
  int drop_a=0, drop_b=0;
  int loop_count = 0;
  int g = 0, w =0, p=0, y=0;
  int drop_count=0;
  cin >> loop_count;

  for(int i=0;i < loop_count;i++){
    for(int j=0;j < 3; j++){
      if(j==0){
        cin >> drop_a;
      }else if(j==1){
        cin >> drop_b;
      }else{
        result = result + drop_b - drop_a + 1;
      }
    }
  }
  cout << result;
}

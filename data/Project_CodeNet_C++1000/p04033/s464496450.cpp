#include <iostream>

using namespace std;

int main(){
  long long a, b;
  cin >> a >> b;
  if (a <= 0 && b >= 0){
    printf("Zero\n");
  }else if (a > 0 && b > 0){
    printf("Positive\n");
  }else{
    long long t = b - a;
    if (t%2 == 0){
      printf("Negative\n");
    }else{
      printf("Positive\n");
    }
  }
}

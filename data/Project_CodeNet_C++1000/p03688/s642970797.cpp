
#include <iostream>
#include <vector>

int main(){
  int n;
  std::cin >> n;
  int num = 1;
  int group = 0;
  int mode = 0;
  bool sw = false;
  for( int i=0; i<n; ++i ){
    int tmp; std::cin >> tmp;
    if (sw)break;
    switch(mode){
      case 0:
        group = tmp; ++mode;
        break;
      case 1:
        if ( group + 1 == tmp ){
          ++group; ++mode;
        } else if ( group - 1 == tmp ){
          num = 1; ++mode;
        } else if ( group == tmp ){
          ++num;
        } else { sw = true; }
        break;
      case 2:
        if ( group - 1 == tmp ){
          ++num;
        } else if ( group != tmp ){
          sw = true;
        }
        break;
    }
  }
  if (sw) {
    puts("No");
    return 0;
  }

  if ( mode == 1 ){
    //std::cout << group << " " << num << std::endl;
    if ( ( group + 1 == n ) || ( group <= n/2 ) ){
      puts("Yes");
    } else {
      puts("No");
    }
  } else {
    group -= num;
    num = n - num;
    //std::cout << group << " " << num << std::endl;
    if ( ( 0 < group ) && ( group <= num/2 ) && ( 1 < num ) ){
      puts("Yes");
    } else {
      puts("No");
    }
  }

  return 0;
}
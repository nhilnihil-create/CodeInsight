#include <iostream>
#include <vector>
using namespace std;

int main(){
#define int int64_t
  int N;
  cin >> N;

  int t = 1;
  int a = 1;

  for(int i = 0;i < N;i++){
    int ti,ai;
    cin >> ti;
    cin >> ai;
    if(ti < t){
      if(ai < a){
	if((a/ai) < (t/ti)){
	  a = ((t + ti - 1)/ti)*ai;
	  t = ((t + ti - 1)/ti)*ti;
	  // std::cout << t << " " << a << " aaa" << std::endl;
	}else{
	  a = ((a + ai - 1)/ai)*ai;
	  t = ((a + ai - 1)/ai)*ti;
	  // std::cout << t << " " << a << " bbb" << std::endl;
	}
      }else{
	a = ((t + ti - 1)/ti)*ai;
	t = ((t + ti - 1)/ti)*ti;
	// std::cout << t << " " << a << " ccc" << std::endl;
      }
    }else{
      if(ai < a){
	a = ((a + ai - 1)/ai)*ai;
	t = ((a + ai - 1)/ai)*ti;
	// std::cout << t << " " << a << " ddd" << std::endl;
      }else{
	a = ai;
	t = ti;
	// std::cout << t << " " << a << " eee" << std::endl;
      }
    }
  }

  std::cout << (a + t) << std::endl;
}

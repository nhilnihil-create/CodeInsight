#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, b, c;
  //cin >> a >> b;
  double ans, ra, rb;
  string dolphinManJotaro;
  cin >> dolphinManJotaro;
  for(int i = 0;i < dolphinManJotaro.size();i++){
    if(dolphinManJotaro[i] == ','){
      cout << " ";
    }else{
      cout << dolphinManJotaro[i];
    }
  }
  return 0;
}

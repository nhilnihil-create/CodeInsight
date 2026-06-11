#include <iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int suma = 0;
  while(n-- > 0){
    int a;
    cin >> a;
  	v.push_back(a);
  	suma +=a;
  }
  int m;
  cin >> m;
  while(m-- > 0){
      int a,b;
      cin >> a >> b;
      cout << suma + (b - v[a-1])<< endl;
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a,b,c;
  string s;
  cin >> a;
  cin >>b;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
   		cin >>s;
      	if(s=="snuke"){
			cout << char('A'+j)<<i+1<<endl;
          return 0;
        }
    }
  }
   return 0;
}

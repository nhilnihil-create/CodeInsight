#include <iostream>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(min(min(b-c,d-a),min(b-a,d-c)),0)<<endl;
}

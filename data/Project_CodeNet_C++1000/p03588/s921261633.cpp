#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  long long n,a,b,bottom = 0,score;cin >> n;
  while(cin >> a >> b){
    if(a>bottom){
      bottom = a;score = b;
    }
  }
  cout << bottom+score << endl;
}
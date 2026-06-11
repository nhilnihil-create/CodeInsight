#include<iostream>
using namespace std;
int main(){
  string ss;
  cin >> ss;
  int len = ss.length();
  int mid = len/2;
  for(int i=0; i<mid; i++){
  	if (ss[i]!=ss[len-1-i]){
  		cout << "No" << endl;
  		return 0;
  	}
  }
  cout << "Yes" << endl;
}

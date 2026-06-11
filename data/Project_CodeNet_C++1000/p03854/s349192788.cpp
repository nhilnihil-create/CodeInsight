#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	string N;
  vector<string> b;
  cin >> N;
  int t = 1;
  for(int i = N.length() - 1;i >= 0;i--){
	if(N.substr(i,t) == "dream" || N.substr(i,t) == "dreamer" || N.substr(i,t) == "erase" || N.substr(i,t) == "eraser"){
		b.push_back(N.substr(i,t));
      t = 0;
    }
    if(t >= 7)break;
    t++;
  }
string check = "";
  for(int i = b.size() - 1;i >= 0;i--){
      check += b.at(i);
  }
  if(N == check){
   cout <<  "YES";
  }else{
	cout <<	"NO";
  }
  cout << endl;
return 0;
}
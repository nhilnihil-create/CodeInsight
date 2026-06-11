#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a;
  //int b[55];
  //vector<int> c(55);
 	int p;
  for(int i=0;i<N;i++){
    cin >> p;
    p--;
    a.push_back(p);
  }
  int now,count=0;
  for(int i=0;i<N;i++){
    
    if(now==1){
      cout << count << endl;
      return 0;
    }
   	count++;
    now=a[now];
  }
   cout << -1 << endl;
}

     
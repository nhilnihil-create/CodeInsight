#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define int long long

signed main(){
  bool flag = true;
  int N;
  int maximum = 0, minimum = (1<<30);
  vector<int> a, con;

  cin>>N;

  a.resize(N);
  con.resize(N);

  for(int i = 0; i < N; i++){
    cin>>a[i];
    con[a[i]]++;

    maximum = max(a[i], maximum);
    minimum = min(a[i], minimum);
  }
  //  cout<<minimum<<endl;
  if((maximum)%2){
    if(con[minimum] != 2) {
      flag = false;
    }
  } else {
    if(con[minimum] != 1) {
      flag = false;
    }
  }

  for(int i = minimum+1; i <= maximum; i++){
    if(con[i] < 2){
      flag = false;
      break;
    }
  }


  if(flag) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;



  return 0;
}

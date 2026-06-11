#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;

signed main(){

  int N;
  int minimum = inf, maximum = 0;
  int minc = 0, maxc = 0;
  vector<int> a;

  cin>>N;

  a.resize(N);

  for(int i = 0; i < N; i++){
    cin>>a[i];

    minimum = min(a[i], minimum);
    maximum = max(a[i], maximum);
  }

  if(maximum - minimum >= 2) {
    cout<<"No"<<endl;
    return 0;
  }

  for(int i = 0; i < N; i++){
    if(a[i] == maximum) maxc++;
    else minc++;
  }




  if(maximum == minimum) {
    if(N-1 == minimum) {
      cout<<"Yes"<<endl;
      return 0;
    }

    int x = N/2;

    if(minimum <= x) {
      cout<<"Yes"<<endl;
      return 0;
    } else {
      cout<<"No"<<endl;
      return 0;
    }
  } else {
    if(maxc == 1) {
      cout<<"No"<<endl;
      return 0;
    }
    int a = minc + 1;
    int b = minc + maxc/2;

    if(a <= maximum && maximum <= b){
      cout<<"Yes"<<endl;
      return 0;
    } else {
      cout<<"No"<<endl;
      return 0;
    }

  }


  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector <int> st(3*N);
  for(int i=0;i < 3*N;i++){
    cin >> st[i];
  }
  sort(st.begin(),st.end());
  int64_t sum=0;
  for(int i=0;i<N;i++){
    sum +=st[N+2*i];
  }
  cout << sum;
}
  
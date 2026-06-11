#include<bits/stdc++.h>
using namespace std;
int main()
{
  int64_t N;
  int64_t G=1;
  int64_t ans=0;
  cin >> N;
  vector<int64_t> A(3*N);
  for(int i=0; i<3*N ; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  
  reverse(A.begin(),A.end());
  for(int j=0; j<N;j++)
  {
    ans=ans+A.at(G);
    G=G+2;
  }
  cout << ans << endl;
}
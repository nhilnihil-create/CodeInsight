#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A;
  long sum=0;
  for(int i=0; i<N; i++)
{
    int a; cin >> a;
    sum+=a;
    A.push_back(a);
  }
  long min = INT_MAX;
  long sum2 =0;
  for(int i=0; i<N-1; i++){
    sum2+=A[i];
    sum-=A[i];
    if(abs(sum2-sum)<min)
{
      min=abs(sum2-sum);
    }
  }
  cout << min << endl;
  return 0;
}

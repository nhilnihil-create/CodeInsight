#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long sum=0;
  long a[N];
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum+=a[i];
  }
  long s=a[0];
  long min=10000000000;
  for(int i=1;i<N-1;i++){
    s+=a[i];
    if(min>abs(sum-2*s))min=abs(sum-2*s);
  }
  if(N==2)min=abs(a[0]-a[1]);
  cout << min;
}


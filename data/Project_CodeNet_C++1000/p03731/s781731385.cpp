#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define show(x) cerr << #x << " = " << x << endl;

int main()
{
  int n, t;
  vector<int> times;


  cin>>n>>t;

  while(n--)
  {
    int e;
    cin>>e;
    times.push_back(e);
  }

  if(times.size()==1)
  {
    cout<<t<<endl;
    return 0;
  }

  long long totalTime = 0;
  for(int i=1;i<times.size();i++)
  {
    long long r = min(t, times[i]-times[i-1]);
    totalTime += r;
  }

  totalTime+=t;

  cout<<totalTime<<endl;


  return 0;
}

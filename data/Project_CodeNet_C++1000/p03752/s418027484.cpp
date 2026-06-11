#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K;
  cin >> N >> K;
  long long a[15]{0};
  for(int i=0;i<N;i++) cin >> a[i];
  
  long long ans=150000000001;
  for(int c=0;c<pow(2,N);c++)
  {
    bool look[15]{false};
    long long yen=0;
    long long nowH=0;
    int count=0;
    for(int i=0;i<N;i++)
    {
      int s=pow(2,i);
      if(c%(2*s)/s==1) 
      {
        count++;
        look[i]=true;
      }
    }
    
    nowH=a[0];
    for(int i=1;i<N;i++)
    {
      if(look[i]==true)
      {
        if(nowH>=a[i])
        {
          nowH++;
          yen+=nowH-a[i];
        }
        else nowH=a[i];
      }
      else if(look[i]==false&&nowH<a[i]) 
      {
        count=0;
        continue;
      }
    }
    //cout << count << endl;
    if(count>=K&&yen<ans) ans=yen;
  }
  
  cout << ans << endl;
  return 0;
}
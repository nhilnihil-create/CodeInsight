#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,W;
  cin >> N >> W;
  int w,v;
  cin >> w >> v;
  vector<int> w0,w1,w2,w3;
  w0.push_back(v);

  for (int i = 1; i < N; i++){
    int wi,vi;
    cin >> wi >> vi;

    if(wi==w) w0.push_back(vi);
    if(wi==w+1) w1.push_back(vi);
    if(wi==w+2) w2.push_back(vi);
    if(wi==w+3) w3.push_back(vi);
  }
  sort(w0.begin(),w0.end(),greater<int>());
  sort(w1.begin(),w1.end(),greater<int>());
  sort(w2.begin(),w2.end(),greater<int>());
  sort(w3.begin(),w3.end(),greater<int>());

  long long ans = 0;
  for (long long i = 0; i <= (long long)w0.size(); i++)
  {
    for (long long j = 0; j <= (long long)w1.size(); j++)
    {
      for (long long k = 0; k <= (long long)w2.size(); k++)
      {
        for (long long l = 0; l <= (long long)w3.size(); l++)
        {
          long long sumw = i*w + j*(w+1) + k*(w+2) + l*(w+3);
          if(sumw<=W){
            long long sumv = 0;
            for (int I = 0; I < i; I++) sumv+=w0[I];
            for (int J = 0; J < j; J++) sumv+=w1[J];
            for (int K = 0; K < k; K++) sumv+=w2[K];
            for (int L = 0; L < l; L++) sumv+=w3[L];
            ans = max(ans,sumv);            
          }
          else break;
        }
      }
    }
  }
  cout << ans << endl;
}
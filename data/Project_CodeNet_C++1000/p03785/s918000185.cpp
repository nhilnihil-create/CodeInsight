#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
char a[10][10];
int main() {
    int N,C,K;
    cin>>N>>C>>K;
    vector<int>T(N);
    for(int i=0;i<N;i++){
      cin>>T[i];
    }
    sort(T.begin(),T.end());
    int count=0;
    for(int i=0;i<N;){
      int start=i;
      int sum=0;
      while(i<N&&T[i]-T[start]<=K&&sum<C){i++;sum++;}
      count++;
    }
    cout<<count<<endl;
return 0;}
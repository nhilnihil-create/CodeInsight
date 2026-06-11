#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
char a[10][10];
int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
      cin>>A[i];
    }
    int count=0;
    for(int i=0;i<N;i++){
      while(i+1<N&&A[i]==A[i+1]){i++;}
      if(i+1<N&&A[i+1]>A[i]){while(i+1<N&&A[i]<=A[i+1]){i++;}}
      else if(i+1<N&&A[i+1]<A[i]){while(i+1<N&&A[i]>=A[i+1]){i++;}}
      count++;
    }
    cout<<count<<endl;
return 0;}
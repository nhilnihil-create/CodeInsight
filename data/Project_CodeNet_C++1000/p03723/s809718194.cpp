#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4

bool possible(int A[3], int &cnt){
  if ((A[0]%2) || (A[1]%2) || (A[2]%2)) return false;

  sort(A,A+3);
  int a=A[0],b=A[1],c=A[2];
  A[0] = (a+b)/2;
  A[1] = (a+c)/2; 
  A[2] = (c+b)/2;

  cnt++;
  return (!(A[0]%2) &&  !(A[1]%2)  && !(A[2]%2));
}

int main(){
  int A[3]; cin >> A[0] >> A[1] >> A[2];

  int cnt = 0;
  while (possible(A,cnt)){
    if (A[0]==A[2]){
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << cnt << endl;
  return 0;
}
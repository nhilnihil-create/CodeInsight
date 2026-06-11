#include<bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)
#define FOR (i,m,n) for(int (i)=m;(i)<(n);(i)++)

int main(){
  int num, start, end, total=0;
  cin >> num;

  REP(i,num){
    cin >> start >> end;
    total+=(end-start+1);
    if(i==(num-1))cout << total << endl;
  }
}


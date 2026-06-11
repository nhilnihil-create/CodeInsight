#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> a;
vector<int> an;

int main(){
  cin >> N;

  a.resize(N+1);  int v;
  for(int i = 1; i <= N; i++){
    cin >> v;
    a[i] = v;
  }

  for(int j =1; j <= N; j++){
    if(a[j] == j) a[j] = 1;            //番号と値が同じなら1を導入
    else a[j] = 0;
  }

  int i = 1; int j = 0; int n = 1;
  while(i+j <= N){                        //1の連続数を配列anに入れる
    while(a[i+j] == n) j++;
      if(j > 0) an.push_back(j);  //j == 0は処理対象じゃない
      i += j + 1;
      j = 0;
  }

  int sum = 0;
  for(int i = 0; i < an.size(); i++)   //1がk個連続していると、すべて処理するには(k+1)/2回
    sum += (an[i]+1)/2;
  cout << sum << endl;
  return 0;
}
    
    

  
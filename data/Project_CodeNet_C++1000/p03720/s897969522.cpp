    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N,M;
      cin >> N >> M;
      vector<int> X(N);//初期化されてる
      int box;
      
      for(int i=0;i<2*M;i++){
        cin >> box;
        X.at(box-1)++;
      }
      for(int i=0;i<N;i++){
        cout << X.at(i) << endl;
      }
      
    }
    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      cin >> N;
      vector<int> X(N);//初期化されてる
      int box=1;
      
      for(int i=0;i<N;i++){
        cin >> X.at(i);
      }
      
      for(int i=0;i<N;i++){
        if(X.at(box-1)==2){
          cout << i+1 << endl;
          break;
        }else{
          box=X.at(box-1);
        }
        if(i==N-1){
          cout << -1 << endl;
        }
      }
      
    }
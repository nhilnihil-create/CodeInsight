    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int N;
      cin >> N;
      int K;
      cin >> K;
      int x;
      int min=0;
      
      // ここにプログラムを追記
      for(int i=0;i<N;i++){
        cin >> x;
        if( K-x > x){
          min+=2*x;
        }else{
          min+=2*(K-x);
        }
      }
      cout << min << endl;
      
    }
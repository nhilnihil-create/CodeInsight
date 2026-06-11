    #include <bits/stdc++.h>
    using namespace std;
         
    int main() {
      int N;
      cin >> N;
      vector<vector<long long>> Ratio(N, vector<long long>(2));
      
      for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
          cin >> Ratio.at(i).at(j);
        }
      }
      
      long long T = Ratio.at(0).at(0);
      long long A = Ratio.at(0).at(1);
   
      
      for(int k = 1; k < N; k++){
        for(long long i = max(max(T / Ratio.at(k).at(0), 1ll), A / Ratio.at(k).at(1) );
            i < max(max(T / Ratio.at(k).at(0), 1ll), A / Ratio.at(k).at(1)) + 2; i++){
            if(T <= Ratio.at(k).at(0) * i && A <= Ratio.at(k).at(1) * i){
            T = Ratio.at(k).at(0) * i;
            A = Ratio.at(k).at(1) * i;
            break;
          }
        }
      }
      
      cout << T + A << endl;
      
      
    }
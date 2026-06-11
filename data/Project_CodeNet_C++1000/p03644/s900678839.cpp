#include <iostream>
using namespace std;


int main() {

  int N,a,b,max_man,out_man;
  int A[210];         // 最大 200 個なので余裕を持って 210 に --- 200 以上ならなんでもよいです

    cin >> N;
    //for (int i = 0; i < N; ++i) cin >> A[i];

    int res = 0;
    max_man = 0;
    out_man = 1;
        for (int i = 1; i <= N; ++i) {
            a = 0;
            b = i;
            //cout << i << endl;
            for (int j = 0; a < 1 ; ++j) {  
                 // cout << b << endl;   
              
                  if (b % 2 < 1){                  
                      b /= 2; 
                    
                  }else {
                       a = 1;
                       //cout << "tooyayo" << endl;          
                   }


                  if (max_man <= j) {
                    max_man = j;
                    out_man = i;
                  } 
                
               }
                                    



        }
    cout << out_man << endl;
}
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>

using namespace std;


int cumsum_A_S[100001];
int cumsum_B_S[100001];
int cumsum_A_T[100001];
int cumsum_B_T[100001];
int main(){
   string S;
   string T;
   cin >> S;
   cin >> T;
   for(int i = 1; i <= S.size(); i++){
     cumsum_A_S[i] = cumsum_A_S[i - 1];
     cumsum_B_S[i] = cumsum_B_S[i - 1];
     if(S[i - 1] == 'A'){
       cumsum_A_S[i] ++;
     }
     if(S[i - 1] == 'B'){
       cumsum_B_S[i] ++;
     }
   }

   for(int i = 1; i <= T.size(); i++){
     cumsum_A_T[i] = cumsum_A_T[i - 1];
     cumsum_B_T[i] = cumsum_B_T[i - 1];
     if(T[i - 1] == 'A'){
       cumsum_A_T[i] ++;
     }
     if(T[i - 1] == 'B'){
       cumsum_B_T[i] ++;
     }
   }

   int q;
   cin >> q;
   for(int i = 0; i < q; i++){
     int a;
     int b;
     int c;
     int d;
     cin >> a >> b >> c >> d;

     int s_a_num = cumsum_A_S[b] - cumsum_A_S[a - 1];
     int s_b_num = cumsum_B_S[b] - cumsum_B_S[a - 1];
     int t_a_num = cumsum_A_T[d] - cumsum_A_T[c - 1];
     int t_b_num = cumsum_B_T[d] - cumsum_B_T[c - 1];
     if(((s_a_num - s_b_num) % 3 + 3) % 3 == ((t_a_num - t_b_num) % 3 + 3) % 3){
       cout << "YES" << endl;
     } else {
       cout << "NO" << endl;
     }
   }
   return 0;
}
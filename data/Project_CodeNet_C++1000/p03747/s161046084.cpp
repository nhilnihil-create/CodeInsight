#include <bits/stdc++.h>
using namespace std;

// To Do:　衝突が発生したときにどっちにいるかの判定
// 全部1か全部2の時の処理

// マイナスの割り算定義
int64_t my_div(int64_t a, int64_t b) {
  if (a>0){
  return a%b; 
  }
  else{
    a = -a;
    if( a % b==0){
      return 0;
    }
    else{
       return b*( a/b + 1) - a;        
     }
  }
}

int main() {
  int64_t N, L, T; 
  cin >> N >> L >> T; 
  int64_t N_1, N_2;  // 向きがiの蟻の数 = N_i
  int64_t ant_index; // 向きが1で座標が一番小さい蟻のindex
  N_1 =0; 
  vector<int64_t> X(N);
  vector<int64_t> W(N);
  int64_t min_of_1 = 1000000000001; 
  for (int64_t i = 0; i < N; i++) {
    	int64_t x, w; 
		cin >> x >> w;
    	X.at(i)=x;
		W.at(i)=w;     
    	if(w==1){ 
          N_1++; 
          if( min_of_1 >= X.at(i) ) {
            min_of_1 = X.at(i);
            ant_index = i; 
          }
        } 
  }
  N_2 = N -N_1;
  
  if(N_2 == 0){
  	for (int64_t i = 0; i < N; i++) {  
      cout << my_div( X.at(i) + T , L )<< endl;  
    }
  }  
  else if(N_1 == 0){
  	for (int64_t i = 0; i < N; i++) {  
      cout << my_div( X.at(i) - T , L )<< endl;  
    }
  }
  else{
  // でかいelse文開始
  
 // min_of_1 を原点とした座標に取り直す
  
  vector<int64_t> X_1(N_1);
  vector<int64_t> X_2(N_2);
   int64_t j_1 = 0 ; 
   int64_t j_2 = 0  ;
   for (int64_t i = 0; i < N; i++) {    
    	if(W.at(i)==1){ 

          	X_1.at( j_1  ) = L - (X.at(i) - min_of_1);
     	    j_1 ++; 
          
        }
     	else{ 
          if( X.at(i) > min_of_1 ){
            X_2.at( j_2 ) =  X.at(i) - min_of_1 ; 
          }
          else{
            X_2.at( j_2  ) =  L + X.at(i) - min_of_1;
          }
          j_2 ++;
        }
  }
  sort(X_1.begin(), X_1.end()); 
  sort(X_2.begin(), X_2.end()); 
  
// X_2に先にぶつかって、X_1にぶつかって、X_2にぶつかってと繰り返す  
  
int64_t i =0;
int64_t j = 1000000836;
int64_t k; 
int64_t a = 0;
int64_t position; 
  
// T秒経過直前のX_1との衝突時刻を探す
while(j-i>1){
 k= (i+j)/2; 
 a = L * ( k/N_2) +  X_2.at( (k % N_2) ) + L * ( k/N_1 ) + X_1.at( (k % N_1) ) ;
 if( a > 2 *T ){
   j = k;
   i = i;
 }
  else{
   i = k;
   j = j; 
  }
}

int flag; //最後の衝突がX_2かX_1か
  
a = L * ( i/N_2) +  X_2.at( (i % N_2) ) + L * ( k/N_1 ) + X_1.at( (i % N_1) ) ;
//　a = Tの前にX_1と衝突した最後の衝突時刻 * 2 ; 
  
 
  // X_1との衝突後に次にX_2と衝突するかどうか
  if( L*(j/N_2) + X_2.at( (j % N_2) ) + L*(i/N_1 ) + X_1.at( (i % N_1) ) <= 2 *T ){
  	//衝突あり, つまり最後の衝突はx_2[j]と
    position = - T + L*(j/N_2) + X_2.at( (j % N_2) )  ;
    flag = 2; 
  }
  else{
    //衝突あり, つまり最後の衝突はx_1[i]と
    position = T   - ( L*(i/N_1 ) + X_1.at( (i % N_1) ) )   ;
    flag = 1; 
  }
  
// 二分探索のコーナーケース
 if( X_1.at(0) + X_2.at(0) > 2*T ){
  if(X_2.at(0) <= 2*T ) {
    position = X_2.at(0) - T ;
    flag = 2; 
  }
  else{
    position = T; 
    flag = 1; 
  }
}
  
  
  position = position + min_of_1; 
  position = my_div(position, L);  
// min_of_1が原点という仮定を外してもどる
// ここまでで、i = ant_indexのT秒後のポジションはpositionであることがわかる

  
vector<int64_t> Y(N); // T秒後の位置 
  for (int64_t i = 0; i < N; i++) {
    if(W.at(i)==1){
      Y.at(i) = my_div( T + X.at(i), L ); 
    }
	else{
      Y.at(i) = my_div( X.at(i) -T , L );       
    }
  }
  
  sort(Y.begin(),Y.end()); 
  


  
  
// For test   
 int64_t ell ; // ell = (ant_indexがYの中で何番目にいるか) 
 for (int64_t i = 0; i < N; i++) { 
//  	cout << Y.at(i) << endl; 
   if(Y.at(i)==position){
       ell = i; // 二個ある場合大きい方
     }
   }

  
  if(  Y.at(ell) == Y.at(ell-1) & flag ==2 ){
    if(ell !=0){
   		 ell = ell -1;
    }
  }
  
  
 
 
 for (int64_t i=0; i< N; i ++) {
   j = my_div( i + ell - ant_index , N ); 
   cout << Y.at( j ) << endl;
 }
  
  
 /* 
 for (int i = 0; i < N_2; i++) { 
  	cout << X_2.at(i) << endl; 
 }
 */
  
}// でかいelse文終了
}
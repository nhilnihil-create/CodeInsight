#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N; cin >> N; string S; cin >> S;
  //o と x 
  vector<bool> assign(N);
  
  //trueが羊、falseが狼を表す。　最初の２つを決めて、その後矛盾がないかを調べていく
 
for(int k = 0; k < 4; k++){
   //4通り試す
   if(k==0){ assign[0] = true; assign[1] = true;}
   if(k==1){ assign[0] = true; assign[1] = false;}
   if(k==2){ assign[0] = false; assign[1] = true;}
   if(k==3){ assign[0] = false; assign[1] = false;}
  
      bool flag = true;      
  
  for(int i = 0; i < N; i++){
    
    if(i == 0){
      if(assign[0]){ 
        if(S[0] == 'o'){ assign[N-1] = assign[1];}
        else{ assign[N-1] = !assign[1];} }
      else{
        if(S[0] == 'o'){ assign[N-1] = !assign[1];}
        else{ assign[N-1] = assign[1];} }
      
      
        }
    
    else if( i < N-2){ 
      //この間は埋めていくだけ
      if(assign[i]){
        if(S[i] == 'o'){ assign[i+1] = assign[i-1];}
        else{ assign[i+1] = !assign[i-1];} }
      else{
        if(S[i] == 'o'){ assign[i+1] = !assign[i-1];}
        else{ assign[i+1] = assign[i-1];} }
    }
   
    else{ // i == N-2とN-1にて、整合するかを確かめる
      
      if( i == N-2){
        
        if(assign[N-2]){
          if(S[N-2] == 'o'){ 
            if( assign[N-1] != assign[N-3]){ flag = false;}}
          else{
            if(assign[N-1] == assign[N-3]){ flag = false;}}
        }
        else{
         
          if(S[N-2] == 'o'){
            if( assign[N-1] == assign[N-3]){ flag = false;}}
          else{
            if( assign[N-1] != assign[N-3]){ flag = false;}}
        }
      }
      else{ // i == N-1のとき
      
        if(assign[N-1]){
          if(S[N-1] == 'o'){
            if( assign[N-2] != assign[0]){ flag = false;}}
          else{
            if( assign[N-2] == assign[0]){ flag = false;}}
        }
        else{ 
          if(S[N-1] == 'o'){
            if( assign[N-2] == assign[0]){ flag = false;}}
          else{
            if( assign[N-2] != assign[0]){ flag = false;}}
        }
      }
     
      if(flag && i == N-1){
        for(int i = 0; i < N; i++){
          if(assign[i]){cout<< "S";} else{ cout << "W";}}
     
        cout << endl; return 0;}
     
    }// i == N-2/N-1かっこ閉じ
 
  }// i - かっことじ

}// k- かっことじ
  
  cout << -1 << endl; return 0;}
          
            
          
                                     
          
            
        
          
      
          
  
  
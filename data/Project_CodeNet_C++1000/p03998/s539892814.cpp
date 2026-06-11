#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	queue<char> a,b,c;
	string ai;
  cin >> ai;
  froop1(0,ai.length()) a.push(ai[i]); 
    cin >> ai;
  froop1(0,ai.length()) b.push(ai[i]); 
    cin >> ai;
  froop1(0,ai.length()) c.push(ai[i]);
  
  char turn = 'a';
  while(1){
    if(turn == 'a'){
      if(a.empty()){
        cout << 'A' << endl;
        return 0;
      }else{
      turn = a.front();
      a.pop();
      }
    }else if(turn == 'b'){
      if(b.empty()){
        cout << 'B' << endl;
        return 0;
      }else{
      turn = b.front();
      b.pop();
      }
    }else{
      if(c.empty()){
        cout << 'C' << endl;
        return 0;
      }else{
      turn = c.front();
      c.pop();
      }
    }
  }
}
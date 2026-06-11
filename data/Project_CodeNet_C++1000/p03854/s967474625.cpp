#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  string s;
  cin >> s;

  string word[4] = {"dream","dreamer","erase","eraser"};

  int pos = s.size();
  int size;
  bool judge = false;

  while(pos > 0){
    judge = false;
    //cout << "pos : " << pos << endl;

    for(int i=0; i<4; i++){
      size = word[i].size();
      if(pos - size >= 0){
        if(s.compare(pos - size, size, word[i]) == 0){
          pos -= size;
          //cout << "i : " << i << endl;
          s.erase(pos,size);
          judge = true;
        }
      }
    }



    if(!judge) break;

  }

  if(judge)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

}

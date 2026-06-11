#include<bits/stdc++.h>
using namespace std;
int main() {
    string S;

  	int cnt=0;
  	bool sum=true;
    cin >> S;
    string pre[4]={"dream", "dreamer", "erase", "eraser" };
    int num=S.size();
    reverse( S.begin(), S.end() );
    for(int i=0;i<4;i++){
      reverse( pre[i].begin(), pre[i].end() );
    }
    
    for(int i=0;i < num;){
bool flag =false;
      for(int j=0;j<4;++j){
        string d = pre[j];
        if (S.substr(i, d.size()) == d){
          flag =true;
          i+=pre[j].size();
        }
      }
      if(!flag){
        sum=false;
        break;
      }
    }

    if(sum) cout << "YES" << endl;
    else cout <<"NO"<< endl;
}
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < (int)n; i++)
using namespace std;
 
int main(){
    int len;
    string S;
    bool flg;
    
    flg = true;
    len = 0;
    
    cin >> S;
    
    reverse(S.begin(),S.end());
    len = S.size();
    
    vector<string> T = {
        "dream","dreamer","erase","eraser"
    };
    
    for(int x = 0; x < T.size(); x++){
        reverse(T.at(x).begin(),T.at(x).end());
    }
    
    
   for(int i = 0; i < len;){
        
        for(int j = 0; j < T.size(); j++){
            if(S.substr(i,T.at(j).size()) == T.at(j)){
                flg = false;
                i += T.at(j).size();
                break;
            }else{
                flg = true;
            }
        }
        
        
        if(flg){
            break;
        }
    }
    
    if(flg){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    
  return 0;
}
#include <bits/stdc++.h>

 
using namespace std;
int main(void){
    string s;
    cin >> s;
    int start_point = 0, flag = 1;
    // cout << s.length() << endl;
    // cout << s.substr(start_point, 5) << endl;
    while(1) {
        if(s.length() == start_point){break;}
        else if(s.length() - start_point < 5){
            flag = 0;
            break;
        }
        //dreamがつく場合
        else if(s.substr(start_point, 5) == "dream"){
            //dream単体だと判定
            if(s.substr(start_point+5, 2) != "er" || s.substr(start_point+5, 5) == "erase" ){
                start_point += 5;
            }
            //dreamer単体だと判定
            else if(s.substr(start_point+5, 2) == "er" && s.substr(start_point+5, 5) != "erase"){
                start_point += 7;
            }
        }
        //eraseがつく場合
        else if(s.substr(start_point, 5) == "erase"){
            //erase単体だと判定
            if(s.substr(start_point+5, 1) != "r"){
                start_point += 5;
            }
            //eraser単体だと判定
            else if(s.substr(start_point+5, 1) == "r"){
                start_point += 6;
            }
        }
        else{
            flag = 0;
            break;
        }
    }

    if(flag == 1){cout << "YES" << endl;}
    else{cout << "NO" << endl;}
  return 0;
}
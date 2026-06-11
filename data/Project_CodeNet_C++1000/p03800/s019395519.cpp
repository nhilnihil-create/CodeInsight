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

char flip(char c){
    if(c == 'S'){
        return 'W';
    }
    return 'S';
}

char next_char(char prev, char cur, char resp){
    if(resp == 'o' && cur == 'S'){
        return prev;
    } else if(resp == 'x' && cur == 'S'){
        return flip(prev);
    } else if(resp == 'o' && cur == 'W'){
        return flip(prev);
    } 
    return prev;
}

char sw[2] = {'S', 'W'};
int main(){
   int N;
   string s;
   cin >> N;
   cin >> s;

    bool possible = false;
   for(int i = 0; i < 2; i++){
       for(int j = 0; j < 2; j++){
           string tmp_ans;
           tmp_ans.push_back(sw[i]);
           tmp_ans.push_back(sw[j]);
           for(int k = 1; k < N - 1; k++){
               tmp_ans.push_back(next_char(tmp_ans[k - 1], tmp_ans[k], s[k]));
           }
           if(next_char(tmp_ans[N - 2], tmp_ans[N - 1], s[N - 1]) == tmp_ans[0] 
                && next_char(tmp_ans[N - 1], tmp_ans[0], s[0]) == tmp_ans[1]){
               cout << tmp_ans << endl;
               return 0;
           }
       }
   }

    cout << -1 << endl;
   return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    vector<char> dir = {'N', 'S', 'E', 'W'};
    vector<int> count(4);
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<4; j++){
            if(s[i] == dir[j]){
                count[j] += 1;
            }
        }
    }
    if((count[0] != 0 && count[1] == 0)
    || (count[1] != 0 && count[0] == 0)
    || (count[2] != 0 && count[3] == 0)
    || (count[3] != 0 && count[2] == 0)){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int start = 0;
    for(; ; start++){
        if(s[start] == 'A') break;
    }

    int goal;
    for(goal = s.length()-1; goal > start; goal--){
        if(s[goal] == 'Z') break;
    }

    cout << goal-start+1 << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int string[s.size()];

    for(int i = 0; i < s.size(); i++){
        string[i] = s[i] - 'a';
    }

    int alp[26] = {0};

    for(int i = 0; i < s.size(); i++){
        alp[string[i]]++;
    }

    int index = -1;

    for(int i = 0; i < 26; i++){
        if(alp[i]==0){
            index = i;
            break;
        }
    }

    char ans = 'a' + index;

    if(index!=-1) cout << ans << endl;
    else cout << "None" << endl;
}
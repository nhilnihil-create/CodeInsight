#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int indexA = -1;
    int indexB = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='A'){
            if(indexA == -1){
                indexA = i;
            }
        }
        if(s[i]=='Z'){
            if(indexA != -1){
                indexB = i;
            }
        }
    }
    cout << indexB - indexA + 1 << endl;
    return 0;
}
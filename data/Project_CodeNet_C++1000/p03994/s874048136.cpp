#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;
    vector<int> dis(s.size());
    for(int i = 0; i < s.size(); i++){
        if('a' + 26 - s[i] == 26) dis[i] = K + 1;
        else dis[i] = 'a' + 26 - s[i];
    }
    for(int i = 0; i < s.size(); i++){
        if(dis[i] <= K){
            s[i] = 'a';
            K -= dis[i];
        }
    }
    if(K > 0){
        s[s.size() - 1] = 'a' + (s[s.size() - 1] - 'a' + K % 26) % 26; 
    }
    cout << s << endl;
}
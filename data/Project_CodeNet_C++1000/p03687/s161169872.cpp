#include <iostream>
#include <string>
using namespace std;

const int INF = 1<<30;

bool contain(string s, char c){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c) return true;
    }
    return false;
}

bool isOK(string s){
    char c = s[0];
    for(int i = 0; i < s.size(); i++){
        if(s[i] != c) return false;
    }
    return true;
}

int numOfOperations(string s, char c){
    int res = 0;
    if(!contain(s,c)) return INF;
    string temp(s.size(), 'a');

    while(!isOK(s)){
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == c || s[i + 1] == c) temp[i] = c;
            else temp[i] = s[i];
        }
        for(int i = 0; i < s.size(); i++){
            s[i] = temp[i];
        }
        s.pop_back();
        res++;
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    int ans = INF;
    for(char c = 'a'; c <= 'z'; c++){
        int n = numOfOperations(s, c);
        if(n < ans) ans = n;
    }
    cout << ans << endl;
}
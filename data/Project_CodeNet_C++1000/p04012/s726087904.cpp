#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    vector<char> alpha;
    for(char c = 'a'; c <= 'z'; c++){
        alpha.push_back(c);
    }
    int t = alpha.size();
    vector<int> num(t, 0);

    for(char c : w){
        for(int i = 0; i < t; i++){
            if(c == alpha[i]){
                num[i] += 1;
                break;
            }
        }
    }

    bool f = true;
    for(int x : num){
        if(x%2 != 0){
            f = false;
            break;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}
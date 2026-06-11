#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    int turn = 1;
    while(1){
        if(turn == 1){
            if(s1.empty()) return cout << "A\n", 0;
            if(s1.back() == 'b'){
                turn = 2;
            }else if(s1.back() == 'c'){
                turn = 3;
            }
            s1.pop_back();
        }else if(turn == 2){
            if(s2.empty()) return cout << "B\n", 0;
            if(s2.back() == 'a'){
                turn = 1;
            }else if(s2.back() == 'c'){
                turn = 3;
            }
            s2.pop_back();
        }else if(turn == 3){
            if(s3.empty()) return cout << "C\n", 0;
            if(s3.back() == 'a'){
                turn = 1;
            }else if(s3.back() == 'b'){
                turn = 2;
            }
            s3.pop_back();
        }
    }
}
/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

string s;
char nw[N];

int main(){
    cin >> s;
    int cnt = 0;
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        while(k >= 2 && nw[k - 2] != s[i]){
            cnt++;
            k--;
        }
        nw[k ++] = s[i];
    }
    if(cnt & 1){
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int N = (int)s.size();
    //区間の数を求める
    int cnt = 0;
    char word = s[0];
    for(int i = 0; i < N;){
        if(word == s[i]){
            while(i < N && word == s[i]){
                i++;
            }
            word = s[i];
            cnt++;
        }else{
            i++;
        }
    }
    cout << cnt-1 << endl;
    return 0;
}
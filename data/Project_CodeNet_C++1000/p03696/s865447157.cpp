#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int now = 0;
    int left = 0;
    int right = 0;
    for (int i = 0;i < n;i++){
        if (s[i] == '(') now++;
        else if (s[i] == ')'){
            if (now > 0) now--;
            else left++;
        }
    }
    rep(i,left) s = '(' + s;
    rep(i,now) s+=')';

    cout << s << endl;

    
    
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int N = s.length();

    map<char, int> m;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(!m[c]) m[c] = 1;
        else m[c]++;
    }

    int np = N/2;
    int win;
    if(np >= m['g']){
        win = m['g'];
    }else{
        win = np;
    }

    int ng = N - np;
    int lose;
    if(ng <= m['p']){
        lose = ng;
    }else{
        lose = m['p'];
    }

    cout << win - lose << endl;

    return 0;
}

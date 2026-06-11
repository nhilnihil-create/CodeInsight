#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int count = 0;
    string S, T = "CODEFESTIVAL2016";
    cin >> S;
    for (int i = 0; i < S.size(); i++){
        if (S.at(i) != T.at(i)){
            count++;
        }
    }
    cout << count << endl;
    
}

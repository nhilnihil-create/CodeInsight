#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <iomanip>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());
    string s;
    cin >> s;
    string res = "Yes";
    string yaki = "YAKI";
    REP(i,yaki.size())
    {
        if(s[i] != yaki[i])res = "No";
    }
    cout << res << endl;
    return 0;
}

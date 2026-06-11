#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll mod = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int main(){
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    string s;
    cin >> s;

    for(int i = 0; i < s.size() -2; ++i)
    {
        if(s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2])
        {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    for(int i = 0; i < s.size() -1; ++i)
    {
        if(s[i] == s[i+1])
        {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }
    


    cout << -1 << " " << -1 << endl;


    return 0;
}

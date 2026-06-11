#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int i, j;
    string s;
    
    cin >> s;
    i = 0;
    while (s[i])
    {
        j = i + 1;
        while (s[j])
        {
            if (s[i] == s[j])
            {
                printf("no\n");
                return (0);
            }
            j++;
        }
        i++;
    }

    printf("yes\n");

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;

vector <string> S;
int main()
{
    int N;
    int L;
    cin >> N >> L;
    S.resize(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if (S[i].compare(S[j]) > 0)
            {
                string tmp;
                tmp = S[i];
                S[i] = S[j];
                S[j] = tmp;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << S[i];
    }
    cout << endl;
}
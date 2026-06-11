#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
 
using namespace std;


void solve(int N, int x) 
{
    if (x <= 1 || x >= N * 2 - 1) 
    {
        cout << "No" << endl;
        exit(0);
    }
    cout << "Yes" << endl;
    vector<int> ans(N * 2 - 1, -1);
    ans[N - 2] = 1;
    ans[N-1] = x;
    ans[N] = N*2-1;
    int ind = 0;
    for (int i = 2; i < N * 2 - 1; i++) {
        if (i == x) 
        	continue;
        while (ans[ind] != -1) 
        	ind++;
        ans[ind] = i;
    }
    for (int i = 0; i < 2 * N - 1; i++)
    {
    	cout << ans[i] << " ";
    }
}

int main() {
    int N, x;
    cin >> N >> x;
    solve(N, x);
}

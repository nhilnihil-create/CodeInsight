#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    scanf("%d", &n);
    
    vector<vector<int> > g(n);

    for(int i = 0;i < n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x -= 1;
        y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> tmp(n);

    function<int (int, int)> go = [&](int i, int par) {
        int xx = 0;
        for (int j : g[i]) if (j != par) {
            xx ^= go(j, i) + 1;
        }
        return xx;
    };

    int ret = go(0, -1);
    if(ret)
    	printf("Alice\n");
    else
    	printf("Bob\n");
    return 0;
}
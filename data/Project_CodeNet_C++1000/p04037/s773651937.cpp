#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N];

bool exist(int x, int y) {
    return y < a[x];
}

bool solve(int x, int y) {
    bool down = exist(x+1, y);
    bool right = exist(x, y+1);
    bool corner = exist(x+1, y+1);

    if (!down && !right)         return false;
    else if (!down)              return (a[x]-y)%2 == 0;
    else if (!right)             return !solve(x+1, y);
    else if (corner)             return solve(x+1, y+1);
    else                         return !solve(x, y+1)  || !solve(x+1, y);
}

int main() {
    int n;
    cin>>n;

    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    reverse(a, a+n);
    bool b = solve(0, 0);

    if (b)  cout<<"First\n";
    else    cout<<"Second\n";
}


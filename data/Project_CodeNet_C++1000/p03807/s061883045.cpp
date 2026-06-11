#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)n;i++)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    int tmp;
    int count = 0;
    rep(i,N)
    {
        cin >> tmp;
        if(tmp % 2 == 1)
            count++;
    }
    if(count % 2 == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}
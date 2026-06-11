#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)n;i++)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    int tmp;
    for(int i = 0;i < N;i++)
    {
        cin >> tmp;
        v[i] = tmp - 1;
    }
    int count = 0;
    for(int i = 0;i < N;i++)
    {
        if(i == v[v[i]])
            count++;
    }
    cout << count / 2 << '\n';
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> x(M), y(M);
    for (int i = 0; i < M; i++)
    {
        int x_in, y_in;
        cin >> x_in >> y_in;
        x[i] = x_in - 1;
        y[i] = y_in - 1;
    }

    vector<int> all(N,1);
    vector<int> red(N,0);
    red[0] = 1;

    for (int i = 0; i < M; i++)
    {
        int from = x[i];
        int to = y[i];

        if(red[from] != 0){
            red[to] = 1;
        }

        all[from]--;
        all[to]++;
        if(all[from] == 0) {
            red[from] = 0;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if(red[i] > 0) cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}

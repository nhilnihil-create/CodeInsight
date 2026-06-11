#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N);
    vector<int> c(M), d(M);

    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }

    for(int j = 0; j < M; j++){
        cin >> c[j] >> d[j];
    }
    
    for(int i = 0; i < N; i++){
        int mindist = 1e9;
        int minj = 0;
        for(int j = 0; j < M; j++){
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(dist < mindist){
                mindist = dist;
                minj = j;
            }
        }
        cout << minj+1 << endl;
    }

    return 0;
}

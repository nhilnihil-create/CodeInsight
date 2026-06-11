#include <bits/stdc++.h>
#define INF 1e9
#define MOD 1000000007
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    
    for (int i = 0; i <= N-M; i++)
    {
        for (int j = 0; j <= N-M; j++)
        {
            bool match = true;
            for (int k = 0; k < M; k++)
            {    
                if(A[i+k].substr(j, M) != B[k]){
                    match =false;
                    break;
                }
            }
            
            if(match){
                cout << "Yes" <<endl;
                return 0;
            }
        }
    }
    
    cout << "No"<< endl;

    return 0;
}

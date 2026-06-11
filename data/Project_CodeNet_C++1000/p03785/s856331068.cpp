#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    int busCnt = 0;
    int passnger = 0;
    sort(T.begin(), T.end(), less<int>());
    
    int tbegin = T[0];
    int tend = T[0] + K;
    passnger++;
    busCnt++;

    for(int i = 1; i < N; i++){
        if(T[i] <= tend && passnger < C) {
            passnger++;
        }

        if(T[i] > tend || passnger >= C){
            busCnt++;
            passnger = 0;
            tend = T[i] + K;
        }
    }

    cout << busCnt << endl;
    
    return 0;
}

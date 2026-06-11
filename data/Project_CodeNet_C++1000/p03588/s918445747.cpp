#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    vector<pair<int, int>> P(N);
    for(int i=0; i<N; i++)
        cin >> P[i].first >> P[i].second;
    
    sort(P.begin(), P.end());
    cout << P.back().first + P.back().second << endl;
}

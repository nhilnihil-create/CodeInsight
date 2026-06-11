#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    set<int> color_set;
    vector<int> a(N);
    int super = 0;
    for(int i=0; i<N; i++) {
        cin >> a[i];
        if(a[i]/400 >= 8) {
            super++;
        }
        else {
            color_set.insert(a[i]/400);
        }
    }
    int n = color_set.size();

    cout << max(1, n) << " " << n+super << endl;

}
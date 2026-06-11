#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N;
    cin >> N;
    vector<Pint> AB(N);
    for (int i = 0; i < N; i++){
        cin >> AB.at(i).first >> AB.at(i).second;
    }
    sort(rALL(AB));
    cout << AB.at(0).first + AB.at(0).second << endl;

}



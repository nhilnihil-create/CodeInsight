#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

typedef pair<ll, int> P;
#define fs first
#define sc second

int main(){
    int N;
    cin >> N;

    P p[N];
    for(int i = 0; i < N; i++){
        cin >> p[i].fs;
        p[i].sc = i;
    }

    sort(p, p + N, greater<P>());

    /*for(int i = 0; i < N; i++){
        cout << p[i].fs << " " << p[i].sc << endl;
    }*/

    int mn[N];
    mn[0] = p[0].sc;
    for(int i = 1; i < N; i++){
        mn[i] = min(mn[i - 1], p[i].sc);
    }

    ll ans[N];
    fill(ans, ans + N, 0);

    for(int i = 0; i < N; i++){
        int id = mn[i];
        if(i == N - 1){
            ans[id] += p[i].fs * (i + 1);
        } else {
            ans[id] += (p[i].fs - p[i + 1].fs) * (i + 1);
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

    return 0;
}

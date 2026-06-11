#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main(){
    int N, T;
    int a[100010];
    int ma[100010];
    int dif[100010];
    cin >> N >> T;
    for(int i = 0; i < N; i++)  cin >> a[i];

    ma[N-1] = a[N-1];
    dif[N-1] = 0;
    for(int i = N-2; i >= 0; i--){
        ma[i] = max(ma[i+1], a[i]);
        dif[i] = ma[i] - a[i];
    }

    sort(dif, dif+N);

    int res = 1;
    for(int i = N-2; i >= 0; i--){
        if(dif[i] < dif[N-1]) break;
        res++;
    }

    cout << res << endl;

    return 0;
}
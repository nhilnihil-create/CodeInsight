#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n, m;
    cin >> n >> m;

    vector<bool> check(n, false);
    vector<int> box(n, 1);

    check[0] = true;
    roop(i, m){
        int a, b;
        cin >> a >> b;
        box[a-1]--;
        box[b-1]++;
        if(check[a-1]) check[b-1] = true;
        if(box[a-1] == 0) check[a-1] = false;
    }


    int ans = 0;
    roop(i, n) if(box[i] > 0 && check[i]) ans++;

    cout << ans << endl;

    return 0;
}
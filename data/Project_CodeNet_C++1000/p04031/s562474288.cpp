#include <bits/stdc++.h>
#define mod 1000000007;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);

    for(auto &i : v)
        cin >> i;

    int res = 2e9;
    for(int i = -100; i <= 100 ; i++){
        int temp = 0;

        for(int s =0 ;  s < N ; s++){
            temp += abs((v[s]-i))* abs((v[s]-i));
        }

        res  = min(temp, res);
    }

    cout << res << endl;

}


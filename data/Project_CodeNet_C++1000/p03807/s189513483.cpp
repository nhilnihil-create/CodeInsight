#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){

    int n;
    cin >> n;

    int sum_odd = 0, sum_even = 0;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(a % 2){
            sum_odd++;
        }else{
            sum_even++;
        }
    }

    if(sum_odd % 2 == 0){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }

    return 0;
}

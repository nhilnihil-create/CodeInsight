#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e+9+7;
int main(){
    //入力
    int N;
    cin >> N;

    vector<int> x(N+1,0);
    for(int i=2;i<=N;i++){
        int num=i;
        for (int j = 2; j <= num; j++) {
            while (num%j == 0) {
                x.at(j)++;
                num /= j;
            }
        }
    }

    ll ans=1;
    for(int i=2;i<=N;i++){
        ans*=(x.at(i)+1);
        ans%=INF;
    }

    cout << ans << endl;
    
}
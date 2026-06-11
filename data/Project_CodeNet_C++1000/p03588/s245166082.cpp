#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int ans=0,M=0;
    for (;N--;){
        int A,B; cin >> A >> B;
        if (M<A) M=A,ans=A+B;
    }
    cout << ans << '\n';
}
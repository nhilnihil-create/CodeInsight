/**
*    author:  souzai32
*    created: 02.08.2020 15:25:02
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long int> a(n),b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);

    long long int ans=0;
    int num;
    for(int i=n-1; i>=0; i--){
        a.at(i)+=ans;
        num=a.at(i)%b.at(i);
        if(num) num=b.at(i)-num;
        ans+=num;
    }

    cout << ans << endl;

    return 0;
}
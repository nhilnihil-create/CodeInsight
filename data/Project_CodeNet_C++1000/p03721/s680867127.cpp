/**
*    author:  souzai32
*    created: 08.08.2020 00:20:35
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long int n,k;
    cin >> n >> k;
    vector<tuple<int,int>> ab(n);
    int a,b;
    rep(i,n){
        cin >> a >> b;
        ab.at(i)=make_tuple(a,b);
    }

    sort(ab.begin(),ab.end());

    int i=0;
    int ans;
    while(i<n){
        k-=get<1>(ab.at(i));
        if(k<=0) break;
        i++;
    }

    cout << get<0>(ab.at(i)) << endl;

    return 0;
}
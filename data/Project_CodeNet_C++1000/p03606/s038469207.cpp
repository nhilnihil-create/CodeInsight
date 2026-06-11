#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main() {
int n;
cin >> n;
int count =0;
rep(i,n){
    int L,R;
    cin >> L >> R;
    int ans = R-L+1;
    count +=ans;
}
cout << count << endl;
}
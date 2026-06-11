#include<bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
vector<long long> a(n), b(n);
long long cp = 0;
for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
for(int i = n; i--;) {
a[i] += cp;
cp += (b[i] - a[i]%b[i])%b[i];
}
cout << cp;
}

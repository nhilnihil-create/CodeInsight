#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;
ll n, a[100500], b[100500];

int main(){

cin >> n; ll sum = 0;
for(int i=1;i<=n;i++){
    cin >> a[i];
    sum += a[i];
}
ll k = n * (n + 1) / 2;
if(sum % k != 0){
    cout << "NO";
    return 0;
}
k = sum / k;
a[n + 1] = a[1];
sum = 0;
for(int i=2;i<=n + 1;i++){
    int x = a[i] - a[i - 1] - k;
    x = -x;
    if(x < 0 || x % n != 0){
        cout << "NO";
        return 0;
    }
    b[i] = x / n;
    sum += b[i];
}
if(sum == k){
    cout << "YES";
}
else cout << "NO";
return 0;
}

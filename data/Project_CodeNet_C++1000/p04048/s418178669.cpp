#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
//priority_queue<int, vector<int>, greater<int> > pq;
#define _CRT_SECURE_NO_DEPRECATE
const int N = 330030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =  1e9+7;
using namespace std;

int main() {
ll n,k;
cin>>n>>k;
cout<<3*(n-__gcd(n,k));

}

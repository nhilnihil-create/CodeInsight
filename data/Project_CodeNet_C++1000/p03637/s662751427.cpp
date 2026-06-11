#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
int n; cin >>n;
vector<int>a(n);
rep(i,n) cin >> a[i];
int f,t,odd;
rep(i,n){
    if(a[i]%4==0) f++;
    else if(a[i]%2==1) odd++;
} 
t = n-f-odd;

if(f==odd) {cout << "Yes" << endl;
return 0;}
if(n==t)
{cout << "Yes" << endl;
return 0;}
if(n%2==1&&n/2==f&&n/2+1==odd)
{cout << "Yes" << endl;
return 0;}

if(odd==0)
{cout << "Yes" << endl;
return 0;}
cout  << "No" << endl;
return 0;
}
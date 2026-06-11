#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
cin >> n;
int a[n],sum=0;

for (int i = 0;i < n;i++) {
    cin >> a[i];
    sum += a[i]%2;
}
sort (a,a+n);
bool can = true;

if (sum%2 != 0){
    can = false;
}
if(can)
    cout << "YES" << endl;
else 
    cout << "NO" << endl;

}
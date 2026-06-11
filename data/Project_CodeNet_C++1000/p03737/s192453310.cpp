#include <bits/stdc++.h>
using namespace std;

string a,b,c;

int main() {
    cin>>a>>b>>c;
    a[0] = a[0] - 'a'+'A';
    b[0] = b[0] - 'a'+'A';
    c[0] = c[0] - 'a'+'A';
    cout<<a[0]<<b[0]<<c[0];
}

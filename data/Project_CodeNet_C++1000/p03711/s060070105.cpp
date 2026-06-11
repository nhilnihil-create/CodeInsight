#include <bits/stdc++.h>

#define ull unsigned long long int
#define ll long long

using namespace std;

long long A[100000+1];

int main() {
    
    int a[] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
    int x, y;
    cin>>x>>y;
    cout<<(a[x] == a[y] ? "Yes" : "No")<<"\n";
    
    return 0;
}
#include <bits/stdc++.h> 
using namespace std; 

#define fori(i,n) for (int i = 0; i < (n); i++)
#define repk(i,k,n)  for (int i = k; i < n; ++i)
#define repr(i,k,n) for (int i = k; i >= n; --i)

int main(void) {
    int a,b,c;
    cin >> a >> b >> c;
    int arr[10] = {0};
    arr[a]++;
    arr[b]++;
    arr[c]++;
    if (arr[5] == 2 && arr[7] == 1) cout << "YES";
    else cout << "NO";
    return 0;
}


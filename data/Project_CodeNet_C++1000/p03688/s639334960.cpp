#include<bits/stdc++.h>
#define reg register
using namespace std;
int n, a[1000001], sum;
int main()
{ 
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    if(a[n] - a[1] > 1) cout << "No\n";
    else if(a[n] - a[1] == 0){
        if(a[1] * 2 > n&&a[1]!=n-1) cout << "No\n";
        else cout << "Yes\n"; 
    }
    else if(a[n] - a[1] == 1){
        for(int i = 1; i <= n; i++)  if(a[i] == a[1]) sum++;
        if(sum >= a[n]) cout << "No\n";
        else if((a[n]-sum) * 2 > n - sum) cout <<"No\n";
        else cout << "Yes\n";
    }
}
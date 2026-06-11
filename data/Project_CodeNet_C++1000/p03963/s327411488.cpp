#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ifstream fin("parimpar2.in");
ofstream fout("parimpar2.out"); 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int n, k;
    cin >> n >> k;
    int ans=k;
    for(int i=0; i<n-1; ++i)
        ans*=k-1;
    cout << ans;
    return 0;
}

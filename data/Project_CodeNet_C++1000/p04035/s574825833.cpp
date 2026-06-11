#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1e5+5;

int ara[MX];

int main(){
     int i, j, k;
     int n, l;
     cin >> n >> l;
     for(i=0; i<n; ++i){
          cin >> ara[i];
     }
     for(i=0; i+1<n; ++i){
          if(ara[i]+ara[i+1]>=l) break;
     }
     if(i>=n-1){
          cout << "Impossible" << endl;
          return 0;
     }
     cout << "Possible" << endl;
     for(j=0; j<i; ++j) cout << j+1 << " ";
     for(j=n-2; j>i; --j) cout << j+1 << " ";
     cout << i+1 << endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<int> r(n);
    for(int i=0; i<n; i++) cin >> r.at(i);
    int cnt=0;
    for(int i=0; i<n; i++){
        int ix = r.at(i)-1;
        if(i == r.at(ix)-1) cnt += 1;
    }
    cout << cnt/2 << endl;
}



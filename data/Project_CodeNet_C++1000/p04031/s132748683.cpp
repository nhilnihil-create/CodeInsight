#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    int cost = 100000000;
    for(int ix=0;ix<n;ix++){
        cin >> a.at(ix);
    }
    for(int ix=-100;ix<=100;ix++){
        int tmp=0;
        for(int ixx=0;ixx<n;ixx++){
            tmp += pow(a.at(ixx) - ix, 2);
        }
        cost = min(cost,tmp);
    }
    cout << cost << endl;
}
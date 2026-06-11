#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> times(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> times.at(i);
    }

    int tsum = 0;

    for(int i=1;i<=n;i++){
        tsum += times.at(i);
    }


    int m = 0;
    cin >> m;
    vector<int> p(m+1);
    vector<int> x(m+1);

    for (int i=1;i<=m;i++){
        cin >> p.at(i) >> x.at(i);
    }

    for(int i=1;i<=m;i++){
        cout << tsum - (times.at(p.at(i))-x.at(i)) << endl;
    }

}
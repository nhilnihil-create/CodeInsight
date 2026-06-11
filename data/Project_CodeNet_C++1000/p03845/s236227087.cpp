#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> t.at(i);
        sum+=t.at(i);
    }
    int m;
    cin >> m;
    vector<int> p(m), x(m);
    vector<int> dist(m);
    for(int i=0; i<m; i++){
        cin >> p.at(i) >> x.at(i);
    }

    int num;
    for(int i=0; i<m; i++){
        dist.at(i)=t.at(p.at(i)-1)-x.at(i);
        cout << sum-dist.at(i) << endl;
    }

}
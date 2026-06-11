#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<long,long> >p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(),p.end());
    cout << p[n-1].first + p[n-1].second << endl;
    
}

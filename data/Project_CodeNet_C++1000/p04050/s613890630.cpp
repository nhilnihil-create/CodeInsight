#include <bits/stdc++.h>
using namespace std;
const int MN = 111;
int a[MN];
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < m; ++i) {
        cin>>a[i];
        if(a[i]%2 == 1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    if(n == 1) {
        cout<<a[0]<<'\n'<<1<<'\n'<<1<<'\n';
        return 0;
    }
    if(odd.size() == 0) {
        for(int i = 0; i < m; ++i) cout<<even[i]<<' ';
        cout<<'\n';
        cout<<m+1<<'\n';
        cout<<even[0]-1<<' ';
        for(int i = 1; i < m; ++i) {
            cout<<even[i]<<' ';
        }
        cout<<1<<'\n';
    }
    else if(odd.size() == 2) {
        vector<int> b;
        if(even.size() == 0) {
            cout<<odd[0]<<' '<<odd[1]<<'\n';
            sort(odd.begin(), odd.end());
            if(odd[1] == 1) {
                cout<<1<<'\n';
                cout<<2<<'\n';
            }
            else {
                cout<<2<<'\n';
                cout<<odd[0]+1<<' '<<odd[1]-1<<endl;
            }
        }
        else {
            cout<<odd[0]<<' ';
            for(int i = 0; i < even.size(); ++i) cout<<even[i]<<' ';
            cout<<odd[1]<<'\n';
            b.push_back(odd[0]+1);
            for(int i = 0; i < even.size(); ++i) b.push_back(even[i]);
            if(odd[1] != 1) b.push_back(odd[1]-1);
            cout<<b.size()<<'\n';
            for(int x: b) cout<<x<<' ';
            cout<<'\n';
        }
    }
    else if(odd.size() == 1) {
        cout<<odd[0]<<' ';
        for(int i = 0; i < even.size(); ++i) cout<<even[i]<<' ';
        cout<<'\n';
        if(even.size()) {
            cout<<m<<'\n';
            cout<<odd[0]+1<<' ';
            for(int i = 0; i+1 < even.size(); ++i) {
                cout<<even[i]<<' ';
            }
            cout<<even.back()-1<<'\n';
        }
        else {
            cout<<2<<'\n'<<odd[0]-1<<' '<<1<<'\n';
        }
    }
    else {
        cout<<"Impossible\n";
    }
}

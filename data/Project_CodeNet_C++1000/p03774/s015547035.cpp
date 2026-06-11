#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    vector<int> d(m);
    for(int i = 0;i < n;i++)cin >> a.at(i) >> b.at(i);
    for(int i = 0;i < m;i++)cin >> c.at(i) >> d.at(i);
    vector<int> ans(n);
    for(int i = 0;i < n;i++){
        int min = INT_MAX;
        int memo, memoJ;
        for(int j = 0;j < m;j++){
            memo = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
            if(min > memo){
                min = memo;
                memoJ = j;
            }
        }
        ans.at(i) = memoJ + 1;
    }
    for(int i = 0;i < n;i++){
        cout << ans.at(i) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

int main(){
    int n;
    cin >> n;
    vector<long long> p(n),a(n+1),b(n+1);
    for (int i=0;i<n;i++) cin >> p.at(i);
    a.at(0)=0;b.at(0)=(n+1)*20000;
    for (int i=1;i<n+1;i++){
        a.at(i)=a.at(i-1)+20000;
        b.at(i)=b.at(i-1)-20000;
    }
    for (int i=0;i<n;i++){
        a.at(p.at(i))+=i;
    }
    for (int i=1;i<n;i++){
        cout << a.at(i) << " ";
    }
    cout << a.at(n) << endl;
    for (int i=1;i<n;i++){
        cout << b.at(i) << " ";
    }
    cout << b.at(n) << endl;
}
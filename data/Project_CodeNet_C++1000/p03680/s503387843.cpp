#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0]=0;

    for(int i=1; i<=n; ++i)
        cin >> a[i];

    int count=0;
    set<int> processed;

    int i=1;
    while(1){
        if(processed.count(i)){
            cout << -1;
            return 0;
        }
        count++;
        processed.insert(i);
        i = a[i];

        if(i == 2){
            cout <<count;
            return 0;
        }
    }
}

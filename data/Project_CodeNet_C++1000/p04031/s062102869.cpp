#include <bits/stdc++.h>
using namespace std;
static const int INF = 1<<20;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> dic;
    for(int i=0; i<n; i++){
        cin>>a[i];
        dic.insert(a[i]);
    }

    int ans = INF;

    for(int num=-100; num<=100; num++){
        int tmp = 0;
        for(int i=0; i<n; i++){
            tmp += ((a[i] - num)*(a[i] - num));
        }

        ans = min(tmp,ans);
    }

    if(dic.size() == 1) ans = 0;

    cout<<ans<<endl;

    return 0;
}
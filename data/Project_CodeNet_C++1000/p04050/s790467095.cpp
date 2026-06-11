#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> even, odd;

    for (int i=0; i<m; i++) {
        int x;
        cin>>x;

        if (x%2)        odd.push_back(x);
        else            even.push_back(x);
    }

    if (odd.size() > 2) {
        cout<<"Impossible"<<endl;
    }
    else if (odd.size() == 0) {
        vector<int> ans = even;
        for (int x: ans)   cout<<x<<" ";
        cout<<endl;

        ans[0]--;
        ans.push_back(1);

        cout<<ans.size()<<endl;
        for (int x: ans)   cout<<x<<" ";
        cout<<endl;
    }
    else if (odd.size() == 1) {
        vector<int> ans = even;
        ans.push_back(odd[0]);

        for (int x: ans)   cout<<x<<" ";
        cout<<endl;

        if (ans.size() == 1)    ans.push_back(0);
        ans[0]--;
        ans.back()++;

        if (ans[0] == 0) ans.erase(ans.begin());

        cout<<ans.size()<<endl;
        for (int x: ans)   cout<<x<<" ";
        cout<<endl;
    }
    else {
        vector<int> ans = even;
        ans.insert(ans.begin(), odd[0]);
        ans.push_back(odd[1]);

        for (int x: ans)   cout<<x<<" ";
        cout<<endl;

        ans[0]++;
        ans.back()--;
        if (ans.back() == 0)    ans.pop_back();
        cout<<ans.size()<<endl;
        for (int x: ans)   cout<<x<<" ";
        cout<<endl;

    }
}





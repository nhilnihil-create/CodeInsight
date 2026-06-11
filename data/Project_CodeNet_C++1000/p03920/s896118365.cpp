#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    int fin = 1;
    int sum = 0;
    while((fin*(fin+1))/2 < n){
        fin++;
    }

    stack<int> st;

    for(int i = fin;i >= 1;i--){
        if(n >= i){
            n -= i;
            st.push(i);
        }
    }

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}


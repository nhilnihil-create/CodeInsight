#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,x;
    cin >> n >> x;

    if(x == 1 || x == 2*n-1){
        printf("No\n");
        return 0;
    }

    vector <int> ans(2*n-1);
    iota(ans.begin() ,ans.end() ,1);
    set <int> st{ans.begin() ,ans.end()};
    ans[n-2] = x-1;
    ans[n-1] = x;
    ans[n] = x+1;
    st.erase(x-1);
    st.erase(x);
    st.erase(x+1);

    for(int i=0; i<2*n-1; i++){
        if(i==n-2||i==n-1||i==n)
            continue;
        ans[i] = *st.begin();
        st.erase(st.begin());
    }

    printf("Yes\n");
    for(int&i : ans)
        printf("%d\n",i);
}

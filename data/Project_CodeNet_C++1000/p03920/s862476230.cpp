#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    int sum = 0;
    set<int> st;
    for(int i = 1;sum < N;i++){
        sum += i;
        st.insert(i);
    }
    for(int i = 1;i*(i+1)/2 <= N;i++){
        if(sum - i == N){
            st.erase(i);
            break;
        }
    }
    for(auto i:st)cout << i << endl;
}
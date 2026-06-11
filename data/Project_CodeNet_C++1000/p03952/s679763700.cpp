#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, x, N;
    cin >> n >> x;
    N = n;
    
    if(x == 1 || 2 * n - 1 == x){
        cout<<"No"<<endl;
        return 0;
    }
    if(n == 2 && x != 2){
        cout<<"No"<<endl;
        return 0;
    }else if(n == 2 && x == 2){
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<2<<endl;
        cout<<3<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    if(x < 2 * n - 2){
        vector<int> is_used(2 * N, 0);
        vector<int> ans(2 * N - 1, -1);
        ans[N - 1] = x;
        ans[N - 2] = x + 2;
        ans[N] = x - 1;
        ans[N + 1] = x + 1;
        is_used[x] = 1;
        is_used[x + 2] = 1;
        is_used[x - 1] = 1;
        is_used[x + 1] = 1;
        int cnt = 0;
        for(int i = 1;i <= 2 * N - 1;i++){
            if(is_used[i] == 0){
                while(ans[cnt] != -1)cnt++;
                ans[cnt] = i;
                cnt++;
            }
        }
        for(auto a : ans)cout<<a<<endl;
    }else{
        vector<int> is_used(2 * N, 0);
        vector<int> ans(2 * N - 1, -1);
        ans[N - 1] = x;
        ans[N - 2] = x - 2;
        ans[N] = x + 1;
        ans[N + 1] = x - 1;
        is_used[x] = 1;
        is_used[x - 2] = 1;
        is_used[x + 1] = 1;
        is_used[x - 1] = 1;
        int cnt = 0;
        for(int i = 1;i <= 2 * N - 1;i++){
            if(is_used[i] == 0){
                while(ans[cnt] != -1)cnt++;
                ans[cnt] = i;
                cnt++;
            }
        }
        for(auto a : ans)cout<<a<<endl;
    }
}

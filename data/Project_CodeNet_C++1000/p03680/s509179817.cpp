#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;

    vector<int> vec(N);
    vector<int> check(N, 0);
    int now = 1;
    int flag = 0;
    int next;
    int count = 0;

    rep(i, N)
    {
        cin >> vec.at(i);
    }

    while(true){
        count++;
        next = vec.at(now - 1);
        if(next == now){
            break;
        }
        if(check.at(next - 1) == 1){
            break;
        }

        if(next == 2){
            flag = 1;
            break;
        }

        now = next;
        check.at(next - 1) = 1;
    }

    if(flag == 1){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
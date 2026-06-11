#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No" << endl;
    }else{
        deque<int> dq;
        dq.push_front(x);
        dq.push_front(x-1);
        dq.push_back(x+1);

        int m = 1;
        for(int i = 1;i <= 2*n-1;i++){
            if(abs(x-i) > 1){
                if(m > 0){
                    dq.push_front(i);
                }else{
                    dq.push_back(i);
                }
                m *= -1;
            }
        }

        cout << "Yes" << endl;
        for(int i = 0;i < 2*n-1;i++){
            cout << dq[i] << endl;
        }
    }

    return 0;
}
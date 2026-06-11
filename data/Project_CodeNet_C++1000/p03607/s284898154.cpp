#include <bits/stdc++.h>

using namespace std;
int main(){
    int N = 0;
    cin >> N;
    vector<long long> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int temp = 0;
    int ans = 0;
    bool now = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (temp == A.at(i))
        {
            if (now)
            {
                ans--;
                now = 0;
            }
            else
            {
                ans++;
                now = 1;
            }
            
        }
        else
        {
            ans++;
            now = 1;
        }
        
        temp = A.at(i);
    }
    cout << ans << endl;
    
}

/*
int main() {
    int N = 0;
    cin >> N;
    vector<int> A(1000000001,0);
    long long temp;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(A.at(temp)) {
            ans--;
            A.at(temp)--;
        } else {
            ans++;
            A.at(temp)++;
        }
    }
    cout << ans << endl;

    return 0;
}
*/
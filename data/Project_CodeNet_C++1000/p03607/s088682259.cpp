#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> A(N);

    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }

    sort(A.begin(),A.end());

    int res = 0;
    int cnt = 1;
    for(int i=0; i<N-1; i++){
        if(A.at(i+1) == A.at(i)){
            cnt++;
        }else{
            if(cnt%2 == 1) res++;
            cnt = 1;
        }

        if(i == N-2 && cnt%2 == 1) res++;
    }

    cout << res << endl;
}
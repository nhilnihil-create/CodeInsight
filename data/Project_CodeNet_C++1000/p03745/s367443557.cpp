#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        while(i+1 < N && A.at(i+1) == A.at(i)){
            i++;
        }
        if(i+1 < N && A.at(i+1) > A.at(i)){
            while(i+1 < N && A.at(i+1) >= A.at(i)) i++;
        }
        else if(i+1 < N && A.at(i+1) < A.at(i)){
            while(i+1 < N && A.at(i+1) <= A.at(i)) i++;
        }
        cnt++;
    }
    cout << cnt << endl;
}
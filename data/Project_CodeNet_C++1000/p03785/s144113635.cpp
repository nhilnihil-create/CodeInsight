#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,C,K;
    cin >> N >> C >> K ;
    vector<int> T(N);
    for(int i=0; i<N; i++){
        cin >> T.at(i);
    }

    sort(T.begin(),T.end());

    int bus_cnt = 0;
    for(int i=0; i<N;){

        int start = T.at(i);
        int time = start;
        int cnt = 1;
        //cout << "bus:" << bus_cnt << " num:" << i << endl;
        i++;
        while(i<N && T.at(i) <= start+K && cnt<C){
           //     cout << "bus:" << bus_cnt << " num:" << i << endl;
                cnt++;
                i++;
        }
        bus_cnt++;
    }

    cout << bus_cnt << endl;
}
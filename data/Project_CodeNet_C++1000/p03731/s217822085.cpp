#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,T;
    vector<int> time;
    cin>>N>>T;
    for(int i = 0; i < N; i++){
        int t;
        cin>>t;
        time.push_back(t);
    }

    int tot = 0;
   
   /*
    9 10
    0 3 5 7 100 110 200 300 311
   */

    int nex = 1;
    if(N==1) tot = T;
    for(int i = 0; i < N-1; i++){
        if(time[i]+T >= time[nex]){
            tot+= time[nex] - time[i];
        }
        else if(time[nex] < time[i]+T){
            tot += T;
        }
        else{
            tot+=T;
        }
        if(i == N - 2) tot+=T;
        nex++;
    }
    cout<<tot<<endl;
}

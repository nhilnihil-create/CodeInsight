#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,ans = 0;
    cin >> N;
    vector<int> V(N,0);
    for(int i = 0;i<N ; i++){
        cin >> V[i];
    }
    for(int i=0;i < N ;i++){
        if(V[V[i]-1]==i+1 && i+1<V[i]){
            ans+=1;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int> > vec(N,vector<int>(2));
    for(int i=0; i<N; i++){
        vec[i] = {1,1000000000};
    }
    int tmp=0;
    for(int i=0; i<N; i++){
        int T;
        cin >> T;

        if (T==tmp){
            vec[i][1]=T;
        }else{
            vec[i]={T,T};
        }
        tmp=T;
    }
    tmp=0;
    vector<int> arr(N,0);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=N-1; i>=0; i--){
        int A=arr[i];

        if (A==tmp){
            vec[i][1]=min(vec[i][1],A);
        }else{
            vec[i]={max(A,vec[i][0]),min(A,vec[i][1])};
        }
        tmp=A;
    }
    long long ans=1;
    for(int i=0; i<N; i++){
        ans*=max(0,vec[i][1]-vec[i][0]+1);
        ans%=1000000007;
    }
    cout << ans << endl;
}
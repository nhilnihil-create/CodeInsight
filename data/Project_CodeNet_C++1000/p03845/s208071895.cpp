#include <bits/stdc++.h>

using namespace std;

queue<vector<int>> que;

void solve(vector<int> vec){

}


int main(void)
{
    int N,M,tmp;
    long long sum=0,ans;
    vector<int> T,P,X;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>tmp;
        T.push_back(tmp);

        sum+=tmp;
    }
    
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>tmp;
        P.push_back(tmp);

        cin>>tmp;
        X.push_back(tmp);
    }

    for(int i=0;i<M;i++){
        ans = sum;
        ans=ans-T[P[i]-1];
        ans=ans+X[i];

        cout<<ans<<endl;
    }





 
	return 0;
}

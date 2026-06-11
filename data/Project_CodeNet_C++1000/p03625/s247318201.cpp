#include<bits/stdc++.h>
using namespace std;

int N,length[100001];
long long ans1,ans2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i = 1;i <= N;i++){
        cin>>length[i];
    }
    sort(length + 1,length + N + 1);
    for(int i = N;i >= 1;i--){
        if(length[i] == length[i - 1] && ans1 == 0) {
            ans1 = length[i];
            i--;
        }
        else if(length[i] == length[i - 1] && ans2 == 0) {
            ans2 = length[i];
            break;
        }
    }
    cout<<ans1 * ans2<<endl;
}

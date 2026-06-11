#include<bits/stdc++.h>
using namespace std;

int N,indeks[100010],ans,number;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i = 1;i <= N;i++){
        cin>>number;
        indeks[number]++;
    }
    for(int i = 1;i <= 100000;i++){
        ans = max(ans, indeks[i - 1] + indeks[i] + indeks[i + 1]);
    }
    cout<<ans<<endl;
}

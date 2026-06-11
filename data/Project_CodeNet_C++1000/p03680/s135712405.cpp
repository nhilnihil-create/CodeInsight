//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,arr[100005];       
bool visited[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int p=1,cnt=0;
    visited[1]=1;
    while(true){
        p=arr[p];
        if(visited[p]){
            //cout<<p<<endl;
            cout<<-1<<endl;
            return 0;
        }
        cnt++;
        visited[p]=1;
        if(p==2){
            cout<<cnt<<endl;
            break;  
        }
    }
}
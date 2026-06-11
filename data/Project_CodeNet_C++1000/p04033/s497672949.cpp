# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int a,b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    if(a<=0 && b>=0){
        cout<<"Zero"<<endl;
        return 0;
    }
    if(a>0){
        cout<<"Positive"<<endl;
    }
    if(a<0){
        a=a-(min(-1,b))+1;
        if(a&1){
            cout<<"Negative"<<endl;
        }
        else cout<<"Positive"<<endl;
    }
}
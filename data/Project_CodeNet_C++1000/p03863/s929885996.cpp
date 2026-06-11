#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
string s;
char arr[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    ll moves=0,k=0;
    for(ll i=0;i<s.size();i++){
        while(k>=2 && s[i]!=arr[k-2])k--,moves++;
        arr[k++]=s[i];
    }
    cout<<((moves%2)?"First":"Second");
}

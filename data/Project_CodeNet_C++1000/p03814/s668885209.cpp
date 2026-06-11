#include<bits/stdc++.h>
#define dbug printf("I am here\n");
#define Fast ios_base::sync_with_stdio(false); cin.tie(0);
#define vs            v.size()
#define ss            s.size()
#define sot(v)        sort(v.begin(),v.end())
#define rev(v)        reverse(v.begin(),v.end())
#define ii            pair<int, int>
#define int           long long
#define ull           unsigned long long
#define pb            push_back
#define mpp           make_pair
#define Okay          0
#define pi            3.14159

const int inf = 1e6;
const int cont = 1e18;
using namespace std;

void solve(){
  string s;
  cin>>s;
  int ans;
  int ans2;
  for(int i=0; i<ss; i++){
    if(s[i] == 'A'){
        ans  = i;
        break;
    }
  }
  for(int i=ss-1; i>=0; i--){
    if(s[i] == 'Z'){
        ans2 = i;
        break;
    }
  }
  cout<<abs(ans-ans2)+1<<endl;
}

int32_t main() {
   Fast;

   solve();
    return Okay;
}


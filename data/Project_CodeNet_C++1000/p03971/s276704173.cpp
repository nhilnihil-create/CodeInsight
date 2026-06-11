#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,cnt=0,bnt=1;
  string s,ans = "No";
  cin  >> n >> a >> b >>s;
  vector<int>k;
  for(int i = 0;i < n;i++){
    ans = "No";
    if(s[i] == 'a'){
    	if((a + b) > cnt){
        	cnt++;
          	ans = "Yes";
        }
    }
    if(s[i] == 'b'){
    	if((a + b) > cnt && bnt <= b){
        	bnt++;
          	cnt++;
          	ans = "Yes";
        }
    }
    cout << ans << endl;
  }
}

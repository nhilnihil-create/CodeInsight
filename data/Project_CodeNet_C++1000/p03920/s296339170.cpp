#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
const int INF = 1<<30;
int main(){
  int n;cin>>n;
  int t=(int)sqrt(n*2)-1;
  while(t*(t+1)<n*2)t++;
  for(int i=1;i<=t;i++){
    if(i==(t*(t+1)/2)-n)continue;
    cout<<i<<endl;
  }
}

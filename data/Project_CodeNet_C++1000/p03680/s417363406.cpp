#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   
   int N,b_num=0,ans=0,i=0;
   cin >> N;
   int data[N];
   
   for(int i=0;i<N;i++) cin >> data[i];
   for(int i=0;i<N;i++) data[i]--;
  
   while(1){
       ans++;
       if(data[b_num] == 1) break;
       int next = data[b_num];
       //if(data[next] == b_num){ans = -1; break;}
       if(i > 1000000){ans = -1; break;}
       b_num = next;
       i++;
   }
   cout << ans << endl;
}
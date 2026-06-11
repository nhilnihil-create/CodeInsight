#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const int MAXN = 500005;
using namespace std;
int arr[MAXN],dp[MAXN];
int main() {
  /* ifstream cin("input.txt");
   ofstream cout("output.txt");*/
   fast_io;
   bool flag=true;
   set<int>set1;
   int n,count=0;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
   		cin>>arr[i];
   }
   int i=0;
   while(set1.size()<=n){

   		if(arr[i]==2){
   			break;
   		}
   		else{
   		if(set1.find(i)==set1.end()){
   			//cout<<arr[i]-1<<endl;
   			set1.insert(i);
   			count++;
   			i=(arr[i]-1);
   			//cout<<count<<" "<<i<<endl;
   		}
   		else{
   			flag=false;
   			break;
   		}
   	  }
   }
   if(flag){
   		cout<<count+1<<endl;
   }
   else{
   		cout<<-1<<endl;
   }
   return 0;
}


   	


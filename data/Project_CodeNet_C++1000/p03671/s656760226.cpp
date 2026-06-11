#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


int main()
{
int arr[3];
cin>>arr[0]>>arr[1]>>arr[2];
sort(arr,arr+3);

cout<<arr[0]+arr[1]<<endl;
 return 0;
}

#include<bits/stdc++.h>
typedef long long int lli;
#define vi vector<int>
#define vs vector<string>
#define pb push_back
#define endl "\n"
#define sortin sort(arr.begin(),arr.end())
#define inputArray for(int i{};i<n;i++){cin>>arr[i];}
#define inputArray1 for(int i{};i<m;i++){cin>>arr1[i];}
#define intloop for(int i{};i<n;i++)
#define intloopminus for(int i{};i<n-1;i++)
#define strloop for(int i{};i<str.length();i++)
#define N int n;cin>>n
#define strlen str.length()
#define InputStr string str;cin>>str
#define twoinputs int n,k;cin>>n>>k
#define T int t;cin>>t;while(t--)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int arr[n];int sum=0;
    for(int i{};i<n;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    int temp=sum;
    temp=ceil(sum/(float)n);
    int floor_sum=0;
    floor_sum=floor(sum/(float(n)));
    int ansCeil=0;int ansFloor=0;
    for(int i{};i<n;i++)
    {
        ansCeil=ansCeil+pow((arr[i]-temp),2);
    }
    for(int i{};i<n;i++)
    {
        ansFloor=ansFloor+pow((arr[i]-floor_sum),2);
    }
    cout<<min(ansCeil,ansFloor)<<endl;
}
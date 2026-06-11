/*
*Bismillahir Rahmanir Rahmin
* @Author: {{Syed Yasir Shahriar
{
/*//*\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\*/
 
//أعوذ بالله من الشيطان الرجيم
//بسم الله الرحمن الرحيم
 
/*//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\*/
 
/*};/* @Date:   {{create_time}}typedef int MyCustomType;
* @Last Modified by:   mrinm
* @Last Modified time: 2020-07-01 22:16:44
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define v vector<ll>
#define st stack<ll>
#define pq  priority_queue <int>
#define q queue<ll>
#define mod 1000000005
using namespace std;
 
 int solve(int arr[],int n){

 	   int res=0;
 	   for (int i =0; i<= n - 1; i++) { 
        int val = 0; 
        for (int j =i; j<= n - 1; j++) { 
            val = val + arr[j]; 
            if (val % 2 != 0) 
                res++; 
        } 
    } 
 	   return (res);
 }
 
int main(){
 /*    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
     //ios::sync_with_stdio(0);
	 int a,b,c;
	 cin>>a>>b>>c;
	 if(c>=a && c<=b){
	 	cout<<"Yes"<<endl;
	 	return 0;
	 }
	cout<<"No"<<endl;
     return 0;
}
/***
*	author  :_shamim
*	created : 05.05.2020
*
***/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <bitset>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)          

using namespace std;

ll i,j,temp;

int main()
{_
	
	int n,digit=0,sum=0,cnt=0;
	cin>>n;

	temp = n;

	while(temp>0){
		temp/=10;
		digit++;
	}
	temp = n;
	int arr[digit];
	while(temp>0){
		arr[cnt] = temp%10;
		cnt++;
		temp/=10;
	}
	for(i=0;i<cnt;i++){
		sum = sum*10 + arr[i];
	}

	if(sum == n){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

	return 0;
}
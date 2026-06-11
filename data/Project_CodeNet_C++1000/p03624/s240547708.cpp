/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define ssll(x,y)    scanf("%lld %lld", &x ,&y)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		string s;
		cin >> s;
		sort (s.begin(),s.end());
		int min = 0;
		map<int,int> num;
		for (int i=0 ; i<(int)s.length() ; i++)
		{
			if(num.count((int)s.at(i) - 97)>0)
			num.at((int)s.at(i) - 97)++;
			else
			num[(int)s.at(i) - 97]=1;
		}
		for (int i=0 ; i<26 ; i++)
		{
			if(num.count(i) == 0)
			break;
			else
			min++;
		}
		if (min == 26) printf("None");
		else 
		cout << (char)(min+97) << endl;
		return 0;
}  

/*

*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <map>
#include<queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int n=s.size();
	int j=n;
	for(j;;j--)
	{
		if(s[j]=='T')
		break;
	}
	int k=0;
	for(k;;k++)
	{
		if(s[k]=='S')
		break;
	 } 
	int tnum=0;
	int snum=0;
	for(int i=k;i<=j;i++)
	{
		
		if(s[i]=='S') 
		{
			snum++;
		}
		if(s[i]=='T') 
		{
			if(snum!=0)
			{
				snum--;
			}
			else
			{
				tnum++;
			}
			
		}
	}
	cout<<k+(n-j)+snum+tnum-1;
	return 0;
}
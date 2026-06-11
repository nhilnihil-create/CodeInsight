/*
Hello don't you know me
I'm the dirt beneath your feet
The most important fool you forgot to see
I've seen how you give it
Now I want to receive
I know that you
Would do the same for me

I know I'm headed for the bottom
But I'm riding you all the way

For all of your kisses turned
To spit in my face
For all that reminds me
Which is my place
For all the times when
You made me disappear
This time I'm sure you will
Know that I'm here

I know I'm headed for the bottom
But I'm riding you all the way

My place was beneath you
But now I'm above
And now I send you a message
Of love
A simple reminder of what
You won't see
A future so holy without me

I know I'm headed for the bottom
But I'm riding you all the way
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

string S="GRYB";

int H,W,d,used[600][600];
int ans[600][600];

bool outside(int a,int b){
	return (a<0||a>=H||b<0||b>=W);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>H>>W>>d;

	if (d%2==1){
	for (int i=0;i<H;i++)
	{
		for (int j=0;j<W;j++)
		{
			if (i%2==j%2)
				cout<<"G";
			else
				cout<<"R";
		}
		cout<<endl;
	}
	return 0;
	}

//	d/=2;

	for (int i=0;i<H;i++)
	{
		for (int j=0;j<W;j++)
		{
			int p1=(j+i)/d;
			int p2=(i-j+100000)/d;
			int a=(p1%2);
			int b=(p2%2);
			cout<<S[a*2+b];
		}
		cout<<endl;
	}

	cin.get(); cin.get();
	return 0;
}

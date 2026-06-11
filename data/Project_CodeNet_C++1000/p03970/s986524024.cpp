#include <bits/stdc++.h>
using namespace std;
int main()
{
	char k[17];//CODEFESTIVAL2016
	gets(k);
	int h=strlen(k);
	int sum=0;
	if(k[0]!='C') sum++;
	if(k[1]!='O') sum++;
	if(k[2]!='D') sum++;
	if(k[3]!='E') sum++;
	if(k[4]!='F') sum++;
	if(k[5]!='E') sum++;
	if(k[6]!='S') sum++;
	if(k[7]!='T') sum++;
	if(k[8]!='I') sum++;
	if(k[9]!='V') sum++;
	if(k[10]!='A') sum++;
	if(k[11]!='L') sum++;
	if(k[12]!='2') sum++;
	if(k[13]!='0') sum++;
	if(k[14]!='1') sum++;
	if(k[15]!='6') sum++;
	cout<<sum<<endl;
	return 0;
 } 
#include <bits/stdc++.h>
using namespace std;
//Á½¸öÊýÏà³ËÊÇ4µÄ±¶Êý£¬ËµÃ÷ÆäÖÐÖÁÉÙÒ»¸öÊÇ4µÄ±¶Êý¡£»òÕßÁ½¸ö¶¼ÊÇ2µÄ±¶Êý
//Í³¼Æ2,4µÄ±¶ÊýµÄ¸öÊý¡£

int main()
{

	int N;
	cin >> N;
	int four = 0,one = 0,two = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a%4==0) four++;
		else if(a%2==0) two++;
		else one++;		//ÆæÊý
	}
	if(one > four+1) //ÓÐ2¸öÊÇ4µÄ±¶Êý£¬µ«ÊÇÓÐ4¸öÆæÊý£¬ÓàÏÂÁ½¸öÆæÊý½«ÎÞ·¨Åä¶Ô 
	{
		cout<<"No\n";
		return 0;
	} 
	if(one == four + 1 && two != 0) {	//2¸öÊÇ4µÄ±¶Êý£¬3¸öÊÇÆæÊý£¬ÇÒÓÐ2µÄ±¶Êý,2µÄ±¶ÊýÔòÒ²²»ÐÐ 
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes";
	return 0;

}

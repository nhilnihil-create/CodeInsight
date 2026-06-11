#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int number_read=0,if_ok_read=1;
	char ch_read=getchar();
	while(ch_read<'0'||ch_read>'9')
	{
		if(ch_read=='-')
			if_ok_read=-1;
		ch_read=getchar();
	}
	while(ch_read>='0'&&ch_read<='9')
	{
		number_read=number_read*10+ch_read-'0';
		ch_read=getchar();
	}
	return number_read*if_ok_read;
}
inline void write(int x_write)
{
    if(x_write<0)
	{
    	putchar('-');
		x_write=-x_write;
	}
    if(x_write>9)
		write(x_write/10);
    putchar(x_write%10+'0');
    return ;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	string s;
    cin>>s;
    printf("%s",((s[0]==s[s.length()-1])^(s.length()%2))?"First":"Second");
	putchar('\n');
	return 0;
}

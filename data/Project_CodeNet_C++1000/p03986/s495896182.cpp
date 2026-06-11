#include <iostream>
#include <string.h>
using namespace std;
void trim(string &s)
{
    int index = 0;
    if( !s.empty())
    {
        while( (index = s.find(' ',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }

}
int main()
{
	string h;
	cin>>h;
	int panduan=0;
	int length;
	
	while(panduan==0)
	{
		panduan=1;
		length=h.size()-1;
		for(int i=0;i<length;++i)
		{
			if(h[i]=='S' && h[i+1]=='T')
			{
				int l=i;int r=i+1;
				while(l>=0 && r<length+1 && h[l]=='S' && h[r]=='T')
				{
					h[l]=' ';h[r]=' ';
					l--;r++;
				}
				panduan=0;
			}
		}
		trim(h);
	}
	cout<<h.size()<<endl;
}
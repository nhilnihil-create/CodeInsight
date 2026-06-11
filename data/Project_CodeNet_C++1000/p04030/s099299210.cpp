//c
#include <stdio.h>
#include <string.h>
int main ()
{
	char key[15];
	scanf ("%s", key);
	
	int a = strlen(key);
	int p=1;
	
	for (int  i = 0; i<a; i++ )
	{
	 int p=1;
		if (key[i] == 'B')
		{
			key[i] = 'x';
			
			if (key[i-1] != 'x')
			{
				key[i-1] = 'x';
			}
			
			else if (key[i-1] == 'x')
			{
				while (key [i-p] != '0' && key [i-p] != '1' )
				{
					p++;
				}
				key[i-p]= 'x';
			}
			
		}
	}
	
	for (int j=0; j<a; j++)
	{
		if (key[j] == 'x')
		{
			continue;
		}
		else
		{
			printf("%c", key[j]);
		}
	}
	
	
	return 0;
}
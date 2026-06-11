//3 key, 0, 1, backspace

//only display 1 string / empty
//when launched, it'll be empty
//then
//if pressed:
//0 --> 0 muncul dikanan
//1 --> 1 muncul dikanan
//backspace --> kalo kosong, ya gaada, kalo ada, yg paling kanan keapus

//Sig launced the editor trs pencet2 key ini
//ada string, itu apa aja yg dia pencet
//0 -> 0, 1 -> 1, B -> backspace
//string yg muncul apa?

//panjang string max 10
//isinya 0,1,B
//output gaboleh empty

//input = string
//output = string akhirnya
//misal sample input
//01B0	-> 0 -> 01 -> 0 -> 00
//0BB1 -> 0 ->  ->  -> 1

#include <stdio.h>
#include <string.h>
int main(){
	char str[11];
	scanf("%s", &str);

	char keluar[11];

	int j = 0, i = 0;
	int len = strlen(str);

	while(len--)		//gantinya for biar pendek
	{
		if(str[j] == 'B')
		{
			if(i > 0)	//kalo dia bkn yg pertama gaada bedanya
			{
				i--;		//kalo bener kondisinya dia mundur 1 index
			}
			keluar[i]= ' ';		//trs diganti jadi kosong, jd kl mau isi bisa2 aja
			j++;	//lanjut
		}
		else
		{
			keluar[i] = str[j];	//isi keluar bernilai sama dengan str (idk biar copy?)
			i++;			//ok it works
			j++;
		}
	}
	
	keluar[i] = '\0';		//mentoknya dimana, nanti dipakein null terminator (kayak titik prinsipnya)
	printf("%s", keluar);
	return 0;
}

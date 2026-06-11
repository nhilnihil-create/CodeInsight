#include <iostream>
#include <string>
using namespace std;

int panjang, panjangout;
string input, output;

int main (){
	cin>>input;
	panjang=input.length();					//biar ga loop ampe mati
	for (int i=0; i<panjang; i++){			
		panjangout=output.length();			//dptin kalo mau delete
		if (input [i]=='B'){
			if (panjangout==0){
				//jgn ngapa2in
			}else{
				output.erase(panjangout-1, 1);				//apus paling belakang
			}
		}else{
			output+=input[i];					//yey ditambah
		}
	}
	cout<<output<<endl;							//bismillah bener
}
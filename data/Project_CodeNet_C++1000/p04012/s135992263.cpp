#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int alfadata[26];//

int main(){
	string str;
	//int str;
	cin>>str;

int n = str.size();
for(int64_t i=0;i < n; i++){
//for(int i=0;i<strlen(str);i++){
	int index = str.at(i)-'a'; //今見ている文字列をアルファベット昇順の順番の数に変換する
	alfadata[index]++; //カウンタを増やす
}

int flag=0; //数え上げたアルファベットの数を確認する

for(int i=0;i<26;i++){
	if(alfadata[i]%2==1)flag=1;
}

	if(flag==0)cout<< "Yes"<<endl;
	else cout<< "No"<<endl;
	
	return 0;

	}

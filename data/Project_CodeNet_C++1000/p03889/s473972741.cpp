//「鏡文」(https://beta.atcoder.jp/contests/cf16-relay-open/tasks/relay_b)

#include<iostream>
#include<string>

int main(){
	//標準入力
	std::string str;
	std::cin>>str;

	//処理
	//鏡文処理をした文字列を作り、比較。
	//メモリが少し無駄だが、まあいいでしょう
	std::string mirrorStr=str;//同じ長さの文字列を用意
	for(size_t i=0,len=str.size();i<len;i++){
		switch(str[len-i-1]){
		case('b'):
			mirrorStr[i]='d';
			break;
		case('d'):
			mirrorStr[i]='b';
			break;
		case('p'):
			mirrorStr[i]='q';
			break;
		case('q'):
			mirrorStr[i]='p';
			break;
		}
	}

	//出力
	std::cout<<(str==mirrorStr?"Yes":"No")<<std::endl;	

	return 0;
}

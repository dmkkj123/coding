#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	getline(cin, s);// 读取含有空格的字符串
	for(int i = s.size() - 1; i >= 0; i--){
		cout << s[i];
	}//翻转倒序输出
	return 0;
}

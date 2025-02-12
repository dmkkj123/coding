#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	getline(cin, s);// 含有空格的string输入
	for(int i = s.size() - 1; i >= 0; i--){
		cout << s[i];
	}//翻转
	return 0;
}

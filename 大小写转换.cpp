#include<bits/stdc++.h>
using namespace std;

char covered(char x){
	if(islower(x)){
		x = toupper(x);
	}else if(isupper(x)){
		x = tolower(x);
	}
	return x;
}
int main(){
	string s;
	getline(cin, s);
	for(auto x : s){
		cout << covered(x);
	}
	cout << endl;
	return 0;
}

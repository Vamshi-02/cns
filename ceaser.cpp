#include<bits/stdc++.h>
using namespace std;
string encrypt(string &t, int k){
	vector<int> asci;
	string code = "";
	int m = t.length();	
	for(auto &ch : t){
		int cyp;	
		if(ch >= 'a' and ch <= 'z')
			cyp = ((int(ch)-97)+k)%26 + 97;			
		else if(ch >= 'A' and ch <= 'Z')
			cyp = ((int(ch)-65)+k)%26 +65;		
		else if(ch >= '0' and ch <= '9')
			cyp = ((int(ch)-48)+k)%26 + 48;
		else
			cyp = int(ch);			
		asci.push_back(cyp);
	}
	int n = asci.size();	
	for(int i = 0; i < n; i++){
		code += char(asci[i]);
	}
	return code;
}
string decrypt(string &code, int k){
	vector<int> asci;
	string text = "";
	for(auto &ch : code){
		int cyp;	
		if(ch >= 'a' and ch <= 'z')
			cyp = ((int(ch)-97)-k)%26 + 97;			
		else if(ch >= 'A' and ch <= 'Z')
			cyp = ((int(ch)-65)-k)%26 +65;		
		else if(ch >= '0' and ch <= '9')
			cyp = ((int(ch)-48)-k)%26 + 48;			
		else
			cyp = int(ch);
		asci.push_back(cyp);
	}
	int n = asci.size();	
	for(int i = 0; i < n; i++){
		text += char(asci[i]);
	}
	return text;
}
int main(){
	string txt;
	cout << "Enter text to be enrypted:";
	getline(cin,txt);
	int k;
	cout << "Enter key value:";
	cin >> k;
	cout << "original text is:-" << txt << endl;
	string encr = encrypt(txt, k);
	string decr = decrypt(encr, k);
	cout << "Encrypted string is:- " << encr << endl;
	cout << "Decrypted string is:- " << decr << endl;
	return 0;
}






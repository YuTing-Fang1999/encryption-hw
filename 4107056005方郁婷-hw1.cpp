#include<stdio.h>
#include <iostream>
#include <string>
using namespace std;

char w[]="abcdefghijklmnopqrstuvwxyz";
string s;
float a;
int key;
int index;
int choice;

void encryption(){
	printf("�п�J�n�[�K��plaintext:\n");
// �i��J�a���Ů檺�r��,�Ů樾�b 
	getline(cin,s);
	
//	key���O��ƪ����b 
	printf("�п�J�A��key(���):");
	while(!(cin >> a) || a-int(a)>0) { 
		cin.clear();
    	cin.sync();
	    cout << "��J�����O��Ƴ�A�ЦA��@��:"; 
	}
	key=int(a);
	char out[10000];
	int i;
	for(i=0;i<s.length();++i){
//		�j�g��p�g�A�j�g���b 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		�u�[�K�p�g�^��r�A��l�r���[�K���b 
		if('a'<=s[i] && s[i]<='z'){
			index=(s[i]-97+26+key)%26;
			s[i]=w[index];
			
		}
		
	}
	printf("�z��ciphertext�O:\n");
	cout<<s<<endl;
}

void decryption(){
	printf("�п�J�n�ѱK��ciphertext:\n");
// �i��J�a���Ů檺�r��,�Ů樾�b 
	getline(cin,s);
	
//	key���O��ƪ����b 
	printf("�п�J�A��key(���):");
	while(!(cin >> a)  || a-int(a)>0) { 
		cin.clear();
    	cin.sync();
	    cout << "��J�����O��Ƴ�A�ЦA��@��:"; 
	}
	key=int(a);
	char out[10000];
	int i;
	for(i=0;i<s.length();++i){
//		�j�g��p�g�A�j�g���b 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		�u�[�K�p�g�^��r�A��l�r���[�K���b 
		if('a'<=s[i] && s[i]<='z'){
			index=(s[i]-97+26-key)%26;
			s[i]=w[index];
		}
		
	}

	printf("�z��plaintext�O:\n");
	cout<<s<<endl;
}
int main(){

	
	
//	�D�Ʀr�����b
	while(true){
		printf("�z�n�A�аݭn�[�K�٬O�ѱK?\n");
		printf("�п�J�Ʀr1(�[�K) or 2(�ѱK):");
		while(true){
			if((cin >> choice)==0){
				cin.clear();
	    		cin.sync();
		    	cout << "�п�J�Ʀr1(�[�K) or 2(�ѱK)��\n"; 
			}else if(choice==1){
				cin.get();
				encryption();
				break;
			}else if(choice==2){
				cin.get();
				decryption();
				break;
			}else{
				cout << "�п�J1(�[�K) or 2(�ѱK)��\n"; 
			}
		}
		
	}
	
}

#include<stdio.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

char w[]="abcdefghijklmnopqrstuvwxyz";
string s;
float a;
char key_str[26];
int c_i=0;
int key;
int index;
int choice;

int stack[100];
int s_i=0;
bool has_neg=false;
int stack_to_num(){
	if(s_i==0) return -1;
	int num=0;
	for(int i=0;i<s_i;++i){
		num+=stack[i]*pow(10,s_i-i-1);
//		printf("%d\n",num);
	}
	if(has_neg){
		num=-num;
		has_neg=false;
	}
	printf("%d",num);
	num=num%26;
	if(num<0) num+=26;
	printf("(%d) ",num);
	s_i=0;
	return num;
} 
void input_key(){
	bool mark[26];
	c_i=0;
	int n=-1;
	
	printf("�п�Jkey: ");
// �i��J�a���Ů檺�r��,�Ů樾�b 
	getline(cin,s);
	printf("���X�Ӫ��r��: ");

	for(int i=0;i<s.length();++i){
		//		�j�g��p�g 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
		
		if('a'<=s[i] && s[i]<='z'){
			n=stack_to_num();//��stack�s���Ʀr���X
			if(n!=-1){ //�p�Gstack���Ʀr���� 
				key_str[c_i++]=w[n];
//				mark[n]=true;
			}
			
			key_str[c_i++]=s[i];
//			mark[s[i]-97]=true;
			
			printf("%c ",s[i]);
		}
		else if(s[i]==','){
				n=stack_to_num();
//				printf("%d\n",n);
				if(n!=-1){ 
					key_str[c_i++]=w[n];
//					mark[n]=true;
				}
		}else if('0'<=s[i] && s[i]<='9'){//��Jstack
			stack[s_i++]=s[i]-48;//��Jstack 
			if(i==s.length()-1){//�p�G�O�̫�@�Ӧr�� 
				n=stack_to_num();
				if(n!=-1){ 
					key_str[c_i++]=w[n];
//					mark[n]=true;
				}
			}
		}
		else if(s[i]=='-'){
			has_neg=true;
		}
	}
	printf("\nkey_str=",key_str);
	for(int i=0;i<c_i;++i){
		printf("%c",key_str[i]);
	}
	cout<<endl;
}
void encryption(){
	printf("�п�J�n�[�K��plaintext:\n");
// �i��J�a���Ů檺�r��,�Ů樾�b 
	getline(cin,s);
		
	int i;
	for(i=0;i<s.length();++i){
//		�j�g��p�g�A�j�g���b 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		�u�[�K�p�g�^��r�A��l�r���[�K���b 
		if('a'<=s[i] && s[i]<='z'){
//			printf("%d\n",s[i]-97);
//			printf("%d\n",key_str[i%c_i]-97);
			index=((s[i]-97)+(key_str[i%c_i]-97))%26;
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
		
	int i;
	for(i=0;i<s.length();++i){
//		�j�g��p�g�A�j�g���b 
		if('A'<=s[i] && s[i]<='Z'){
			s[i]+=32;
		}
//		�u�[�K�p�g�^��r�A��l�r���[�K���b 
		if('a'<=s[i] && s[i]<='z'){
			index=((s[i]-97)-(key_str[i%c_i]-97)+26)%26;
			s[i]=w[index];
		}
	}
	printf("�z��plaintext�O:\n");
	cout<<s<<endl;
	
}
int main(){
	printf("�w�]�H�r���M���(�i��J�t��)�����j�}\n�p�G���[ ',' �|��','�u���j�}\n");

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
				input_key();
				encryption();
				break;
			}else if(choice==2){
				cin.get();
				input_key();
				decryption();
				break;
			}else{
				cout << "�п�J1(�[�K) or 2(�ѱK)��\n"; 
			}
		}
		
	}
	
}

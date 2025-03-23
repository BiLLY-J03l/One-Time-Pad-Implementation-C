#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encrypt(FILE* plain_file, FILE* encrypted_file,FILE* key_file){
	
	int character;
	printf("[+] loading source of entropy..\n");
	srand(time(0)); 
	printf("[+] Encrypting..\n");
	while( (character=fgetc(plain_file)) != EOF ){
		
		
		//Use current time as seed for random generator
		srand(time(0)); 
		
		// Generates a pseudorandom number
		int key = rand();	
	
		int encrypted_character = character ^ key;
		
		fputc(key,key_file);
		fputc(encrypted_character,encrypted_file);
	}
	printf("[+] File encrypted and written!\n");
	return;
}

int main(int argc, char **argv) {

	if (argc != 2){
		printf("[x] supply the program with a file to encrypt\n");
	}
	else{
		
		char* plain_file_name=argv[1];
		FILE* plain_file=fopen(plain_file_name,"r");
		FILE* encrypted_file=fopen("crypt.out","w");
		FILE* key_file=fopen("key.out","w");
		encrypt(plain_file,encrypted_file,key_file);
		fclose(plain_file);
		fclose(encrypted_file);
		fclose(key_file);
	}
	
    return 0;
}

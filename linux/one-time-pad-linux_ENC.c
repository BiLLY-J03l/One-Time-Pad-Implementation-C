#include <stdio.h>
#include <stdlib.h>

void encrypt(FILE* plain_file, FILE* encrypted_file,FILE* key_file){

    
    FILE* urandom = fopen("/dev/urandom", "rb");
    if (urandom == NULL) {
        perror("Failed to open /dev/urandom");
        exit(1);
    }





	int character;


	printf("[+] Encrypting..\n");
	while( (character=fgetc(plain_file)) != EOF ){
		
		int key;
		int result = fread(&key, sizeof(key), 1, urandom);
	    if (result != 1) {
			perror("Failed to read random number");
			fclose(urandom);
			exit(1);
		}
	
		int encrypted_character = character ^ key;
		
		fputc(key,key_file);
		fputc(encrypted_character,encrypted_file);
	}
	printf("[+] File encrypted and written!\n");
	fclose(urandom);
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void decrypt(FILE* encrypted_file, FILE* key_file,FILE* decrypted_file){
	
	int encrypted_character;

	printf("[+] Decrypting..\n");
	while( (encrypted_character=fgetc(encrypted_file)) != EOF ){
		
		int key_character = fgetc(key_file);
	
		int decrypted_character = encrypted_character ^ key_character;
		
		
		fputc(decrypted_character,decrypted_file);
	}
	printf("[+] File decrypted and written!\n");
	return;
}

int main(int argc, char **argv) {

	if (argc != 3){
		printf("[x] USAGE: %s <encrypted file> <key file>\n",argv[0]);
	}
	else{
		FILE* encrypted_file=fopen(argv[1],"r");
		FILE* key_file=fopen(argv[2],"r");
		FILE* decrypted_file=fopen("decrypt.out","w");
		decrypt(encrypted_file,key_file,decrypted_file);
		fclose(decrypted_file);
		fclose(encrypted_file);
		fclose(key_file);
	}
	
    return 0;
}

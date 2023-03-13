#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
// #include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

#define ALPHABET "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM[]{}<>()*#"
#define HELP_MESSAGE "\tpwdgen <quantity> - generates a password of the given size from the standard alphabet\n"\
					 "\tpwdgen <alphabet> - generates four characters from the given alphabet\n"\
					 "\tpwdgen <alphabet> <quantity> - generates a password of the given length from the given alphabet\n"\
					 "\tpwdgen - generates a four character password from the standard alphabet\n"

char *get_random_string(const char *alphabet, int quantity) {
	// printf("%s\n%ld\n", alphabet, strlen(alphabet));
	srand(time(NULL));
	char *str = malloc(sizeof(char*) * quantity);
	for (int i = 0; i < quantity; i++) {
		str[i] = alphabet[0+rand()%strlen(alphabet)];
	}
	return str;
}

// char *get_file_extension(char *filename) {
// 	char *p = NULL;
//     int i,l;
//     l=strlen(filename);
//     for (i=l-1; i>=0; i--)
//         if (filename[i]=='.')
//         {
//             p=filename+i+1;
//             break;
//         }
//     return p;
// }

// int64_t getFileSize(FILE *file_name){
// 	int64_t _file_size = 0;
// 	struct stat _fileStatbuff;
// 	if ((fstat(fileno(file_name), &_fileStatbuff) != 0) || (!S_ISREG(_fileStatbuff.st_mode))) {
// 		_file_size = -1;
// 	}
// 	else{
// 		_file_size = _fileStatbuff.st_size;
// 	}
// 	return _file_size;
// }

int main(int argc, char *argv[]) {
	if (argc == 2) {
		if (!strcmp(argv[1], "-h")) {
			printf("%s\n", HELP_MESSAGE);
			return 0;
		} else if (atoi(argv[1]) > 0) {
			int quantity = atoi(argv[1]);
			char *pwd = get_random_string(ALPHABET, quantity);
			printf("Password -> %s\n", pwd);
			return 0;
		} else if (atoi(argv[1]) == 0) {
			// char *file_extension = get_file_extension(argv[1]);
			// printf("%s\n", file_extension);
			// printf("%s\n%d\n%d\n", argv[1], strcmp(file_extension, ""), strcmp(file_extension, "txt"));
			// if (!strcmp(file_extension, "txt")) {
			// 	FILE *alphabet_file = fopen(argv[1], "r");
			// 	if (alphabet_file == NULL) {
			// 		printf("Can't open file\n");
			// 		return 1;
			// 	}
			// 	int64_t size = getFileSize(alphabet_file);
			// 	// printf("%ld\n", size);
			// 	char alphabet[size];
			// 	fgets(alphabet, size+1, alphabet_file);
			// 	for (int i = 0; i < size; i++){
			// 		if (alphabet[i] == '\n') {
			// 			printf("nononono");
			// 		}else {
			// 			printf("%c\n", alphabet[i]);
			// 		}
			// 	}
			// 	fclose(alphabet_file);
			// 	char *pwd = get_random_string(alphabet, 4);
			// 	printf("Password -> %s\n", pwd);
			// }
			// printf("%s\n", get_file_extension(argv[1]));
			char *pwd = get_random_string(argv[1], 4);
			printf("Password -> %s\n", pwd);
			return 0;
		}
	}
	if (argc == 3) {
		int quantity = atoi(argv[2]);
		char *alphabet = argv[1];
		char *pwd = get_random_string(alphabet, quantity);
		printf("Password -> %s\n", pwd);
		return 0;
	}
	char *pwd = get_random_string(ALPHABET, 4);
	printf("Password -> %s\n", pwd);
	return 0;
}

// int64_t getFileSize(const char* file_name){
// 	int64_t _file_size = 0;
// 	FILE* fd = fopen(file_name, "rb");
// 	if(fd == NULL){
// 		_file_size = -1;
// 	}
// 	else{
// 		while(getc(fd) != EOF)
// 			_file_size++;
// 		fclose(fd);
// 	}
// 	return _file_size;
// }
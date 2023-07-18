#include <stdio.h>
#include <stdint.h>

uint32_t main(int argc, char** argv) {
	if(argc==3){

		FILE* fp;
		fp= fopen(argv[1], "rb");
	        FILE* fp2;
		fp2= fopen(argv[2], "rb");

		if (fp == NULL || fp2 == NULL){
               		printf("error!");
	               return 1;
          	}

		int num1, num2;
		fread(&num1, sizeof(int),1, fp);
    		fread(&num2, sizeof(int),1, fp);

		printf("%d %d\n", num1, num2);
    
		
		fclose(fp);
	}
}


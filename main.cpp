#include<stdio.h>
#include<stdint.h>


uint32_t nbo(uint32_t n){
	uint32_t a=(n & 0xFF000000) >> 24;
	uint32_t b=(n & 0x00FF0000) >> 8;
	uint32_t c=(n & 0x0000FF00) << 8;
	uint32_t d=(n & 0x000000FF) << 24;
	return a|b|c|d;
}

int main(int argc, char** argv){
	
	if(argc==3){
        
		FILE *fp;
		FILE *fp2;
		uint32_t num1,num2;
		
		fp=fopen(argv[1],"rb");
		fp2=fopen(argv[2],"rb");
		
		fread(&num1, sizeof(uint32_t), 1, fp);
		fread(&num2, sizeof(uint32_t), 1, fp2);
		
		num1=nbo(num1);
		num2=nbo(num2);
		
		printf("%d(0x%02x) + ",num1,num1);
		printf("%d(0x%02x) ",num2,num2);
		
		int result=num1+num2;
		printf("= %d(0x%02x)",result,result);
		
		fclose(fp);
		fclose(fp2);
	}
}

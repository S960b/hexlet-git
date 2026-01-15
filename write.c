
#include <stdio.h>
int main(void) { 
FILE *file = fopen("res.txt","w"); 
for (int i=0;i<100;i++){
		fprintf(file,"%d\n",i);
	
	};
fclose(file); return 0;
}

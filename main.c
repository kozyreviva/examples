#include <stdio.h>
#include <stdlib.h>

int move(int *mas, int n, int k);
int invert(int *mas, int n);

int main(int argc, char *argv[]) {
	int *mas=0;
	int n,k,nmax,res;
	k=nmax=0;
	FILE *file;
	char filename[256];
	
	printf("Move massive right on \"k\"\n\nEnter filename =>  ");
	scanf("%s",&filename);
	file = fopen(filename,"r");
	if(!file) {
		printf("File not found!!!");
		return -1;
	}
	
	if(fscanf(file,"%d",&nmax)==EOF) {
		printf("Massive length error!\n");
		return -1;
	}
	if(nmax<=0) {
		printf("Massive length error!\n");
		return -1;
	}
	
	mas = (int*)malloc(nmax*sizeof(int));
	if(!mas){
		printf("Need more memory!!!");
		return -1;
	}
	printf("Massive:\n");
	for(n=0;n<nmax && fscanf(file,"%d",&mas[n]) != EOF; n++)
		printf("mas[%d] = %d\n",n,mas[n]);
		
	printf("Enter number \"k\" for right shift => ");
	scanf("%d",&k);
	
	res = move(mas,n,k);
	
	fclose(file);
	
	printf("\n\nMassive result: %s\n\n",(res)?"true":"false");
	for(n=0;n<nmax;n++)
		printf("mas[%d] = %d\n",n,mas[n]);
		
	return 0;
}

int move(int *mas,int n,int k) {
	int i,t,s;
	k%=n;
	for(s=0;s<k;s++) {
		t= mas[n-1];
		for(i=n-1;i>0;i--) {
			mas[i] = mas[i-1];
		}
		mas[0] = t;
	}
}

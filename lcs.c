#include<stdio.h>
#include<stdio.h>
#include<string.h>
char b[50][50];
int c[50][50];

void LCS_LENGTH(char X[],char Y[],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		c[i][0]=0;
	}
	for(j=0;j<n;j++){
		c[0][j]=0;
	}
	//D-diagonal,L-left,R-right,T-top
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='D';
			}
		        else if(c[i-1][j]>=c[i][j-1]){
			        c[i][j]=c[i-1][j];
	                        b[i][j]='T';
			}
			else{
			        c[i][j]=c[i][j-1];
			        b[i][j]='L';
			}

		}
	}
}

void PRINT_LCS(char X[],int i,int j){
	if(i==0 || j==0)
		return ;
        //D-diagonal,L-left,R-right,T-top
        if(b[i][j]=='D'){
	     PRINT_LCS(X,i-1,j-1);
             printf("%c ",X[i-1]);
	}
       else if(b[i][j]=='T'){
	     PRINT_LCS(X,i-1,j);
       }
       else{
	     PRINT_LCS(X,i,j-1);
       }
 }
void display(int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%c ",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");		
	}
}
	
int main(){
	char X[50],Y[50];
	printf("Enter the first sequence:\n");
	scanf("%s",X); 

	printf("ENter the second sequence:\n");
	scanf("%s",Y);

	int l1,l2;
	l1=strlen(X);
	l2=strlen(Y);
        LCS_LENGTH(X,Y,l1,l2);
        display(l1,l2);
	printf("Length of longest subsequence:%d\n",c[l1][l2]);
        printf ("lcs sequence is: ");
	PRINT_LCS(X,l1,l2);
	printf("\n");
}

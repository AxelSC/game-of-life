#define EL 1001

#include <stdio.h>
int main(){
	char r;
	int g,m,n,k,i=0,j=0,sv,a[EL][EL],c[EL][EL];
	float pop,popmax=0;
	scanf("%c%d%d%d",&r,&m,&n,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//matricea poate fi plan sau toroid
   switch(r){
		case 'P':{
			//numarul de generatii
			for(g=0;g<k;g++){
				pop=0;
				for(i=0;i<n;i++){
					for(j=0;j<m;j++){
								sv=0;
								pop=pop+a[i][j];
								//9 cazuri diferite
								if(i==0){
									if(j==0){
										sv=a[i][j+1]+a[i+1][j]+a[i+1][j+1];
									}
									else if(j==m-1){
										sv=a[i][j-1]+a[i+1][j-1]+a[i+1][j];
										}
									else{
										sv=a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
									}
								}
								else if(i==n-1){
									if(j==0){
										sv=a[i-1][j]+a[i-1][j+1]+a[i][j+1];
									}
									else if(j==m-1){
										sv=a[i-1][j-1]+a[i-1][j]+a[i][j-1];
										}
									else{
										sv=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1];
									}
								}
								else{
									if(j==0){
										sv=a[i-1][j]+a[i-1][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
										}
									else if(j==m-1){
										sv=a[i-1][j-1]+a[i-1][j]+a[i][j-1]+a[i+1][j-1]+a[i+1][j];
										}
									else{
										sv=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
										}
									}
									//starea celulei in generatia urmatoare
								if(sv<2){
									c[i][j]=0;
								}
								else if(sv>3){
									c[i][j]=0;
								}
								else if(sv==3){
									c[i][j]=1;
								}
								else{
									c[i][j]=a[i][j];
								}
							}
						}
					if(pop>popmax){
						popmax=pop;
						}
					for(i=0;i<n;i++){
						for(j=0;j<m;j++){
							a[i][j]=c[i][j];
						}
					}
				}
				break;}
		case 'T':{
			//numarul de generatii
			for(g=0;g<k;g++){
				pop=0;
				for(i=0;i<n;i++){
					for(j=0;j<m;j++){
							sv=0;
							pop=pop+a[i][j];
							//9 cazuri diferite
								if(i==0){
									if(j==0){
										sv=a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i][m-1]+a[i+1][m-1]+a[n-1][j]+a[n-1][j+1]+a[n-1][m-1];
									}
									else if(j==m-1){
										sv=a[i][j-1]+a[i+1][j-1]+a[i+1][j]+a[i][0]+a[i+1][0]+a[n-1][0]+a[n-1][j-1]+a[n-1][j];
										}
									else{
										sv=a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1]+a[n-1][j-1]+a[n-1][j]+a[n-1][j+1];
									}
								}
								else if(i==n-1){
									if(j==0){
										sv=a[i-1][j]+a[i-1][j+1]+a[i][j+1]+a[0][j]+a[0][j+1]+a[0][m-1]+a[i-1][m-1]+a[i][m-1];
									}
									else if(j==m-1){
										sv=a[i-1][j-1]+a[i-1][j]+a[i][j-1]+a[0][j-1]+a[0][j]+a[0][0]+a[i-1][0]+a[i][0];
										}
									else{
										sv=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[0][j-1]+a[0][j]+a[0][j+1];
									}
								}
								else{
									if(j==0){
										sv=a[i-1][j]+a[i-1][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i-1][m-1]+a[i][m-1]+a[i+1][m-1];
										}
									else if(j==m-1){
										sv=a[i-1][j-1]+a[i-1][j]+a[i][j-1]+a[i+1][j-1]+a[i+1][j]+a[i-1][0]+a[i][0]+a[i+1][0];
										}
									else{
										sv=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
										}
									}
									//starea celulei in generatia urmatoare
								if(sv<2){
									c[i][j]=0;
								}
								else if(sv>3){
									c[i][j]=0;
								}
								else if(sv==3){
									c[i][j]=1;
								}
								else{
									c[i][j]=a[i][j];
								}
							}
						}
					if(pop>popmax){
						popmax=pop;
						}	
					for(i=0;i<n;i++){
						for(j=0;j<m;j++){
							a[i][j]=c[i][j];
						}
					}
			}
            break;
			}
		}
	popmax=(popmax/(m*n))*100;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",a[i][j]);
			}
		printf("\n");
		}
		printf("%.3f%%",popmax);
	return 0;
}

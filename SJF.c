#include<stdio.h>

void main() {
	
	int i,j,k,n,sum,wt[10],tt[10],twt,ttat;
	int t[10],p[10];
	float awt,atat;
	
	printf("Enter number of process\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
	printf("\nEnter the Burst Time of Process %d",i);
	scanf("\n%d",&t[i]);
	}
	
	for(i=0;i<n;i++)
		p[i]=i;
	for(i=0;i<n;i++) {
			for(k=i+1;k<n;k++) {
				if(t[i]>t[k]) {
		
		int temp;
		temp=t[i];
		t[i]=t[k];
		t[k]=temp;
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
		} 
		}
	printf("\n\nSJF SCHEDULING ALGORITHM");
	printf("\nPROCESSID\tBURSTTIME\tWAITINGTIME\tTURNAROUNDTIME\n\n");
	wt[0]=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(k=0;k<i;k++) {
			wt[i]=sum+t[k];
			sum=wt[i];
		}
	 }
	for(i=0;i<n;i++)
	{
	tt[i]=t[i]+wt[i];
	}
	
	for(i=0;i<n;i++) {
		printf("%5d\t\t%d\t\t%5d\t\t%5d\n\n",p[i],t[i],wt[i],tt[i]);
	}
	
	twt=0;
	ttat=t[0];
	for(i=1;i<n;i++) {
		twt=twt+wt[i];
		ttat=ttat+tt[i];
	}
	
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("\nAVERAGE WAITING TIME%4.2f",awt);
	printf("\nAVERAGE TURNAROUND TIME%4.2f",atat);
	
	getch();
	}
}

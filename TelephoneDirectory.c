#include <stdio.h>
#include <conio.h>
#include <string.h>

struct person{
	 char name[20];
	 char address[50];
	 long telno;
};

void fillData(){
	  FILE *fp;
	  struct person obj;
	  clrscr();
	  fp=fopen("data.txt","a");
	  printf("\n=======================================");
	  printf("\n===== Add Record in the Database ======");
	  printf("\n=======================================");
	  printf("\n\n");
	  printf("Enter Name of the Person : ");
	  scanf("%s",obj.name);
	  printf("Enter the Address        : ");
	  scanf("%s",obj.address);
	  printf("Enter Telephone No. : ");
	  scanf("%ld",&obj.telno);
	  fprintf(fp,"%20s %20s %7ld",obj.name,obj.address,obj.telno);
	  fclose(fp);
}

void showData(){
	  FILE *fp;
	  struct person obj;
	  char name[20];
	  char address[50];
	  clrscr();
	  fp=fopen("data.txt","r");
	  printf("\n\t\t=================================");
	  printf("\n\t\t====== Display All Records ======");
	 printf("\n\t\t=================================");
	  printf("\n\n\t\tName   \t\t Address    \t\tTelephone No.");
	  printf("\n\t\t=======  \t==========  \t\t============\n\n");
	  while(!feof(fp))
	  {
	   fscanf(fp,"%20s %20s %7ld",obj.name,obj.address,&obj.telno);
	  printf("%20s  %20s %25ld\n",obj.name,obj.address,obj.telno);
	  }
	  fclose(fp);
	  getch();
}

void findData(){
	  FILE *fp;
	  struct person obj;
	  char name[20];
	  char address[50];
	  int total=0;
	  clrscr();
	  fp=fopen("data.txt","r");
	  printf("\n======================================");
	  printf("\n===== Display Specific Records =======");
	  printf("\n======================================");
	 printf("\n\n");
	  printf("\nEnter the Name of the Person : ");
	  scanf("%s",&name);
	  while(!feof(fp))
	  {
	 fscanf(fp,"%20s %20s %7ld",obj.name,obj.address,&obj.telno);
	     if(strcmpi(obj.name,name)==0){
		printf("\n\nName      :  %s",obj.name);
		printf("\nAddress   :  %s",obj.address);
		printf("\nTelephone No : %ld",obj.telno);
		total++;
	     }
	  }
	  if(total==0)
	     printf("\n\n\n\t\t Sorry the record cannot be found in the database.");
	  else
	     printf("\n\n===Total %d Record found===",total);
	  fclose(fp);
	  getch();
}


void quit() {
  
  exit(0);
  
  }
void main(){
	  char choice;
	  while(1){
	clrscr();
	printf("======================================================");
	printf("\n====== Telephone Directory Database  ======");
	printf("\n======================================================");
	printf("\n\n\t 1) Add Record in the Datbase\n");
	printf("\t 2) Find Record in the Database\n");
	printf("\t 3) Read all records in the Database\n");
	printf("\t 4) Quit Program\n");
	printf("\n\n");
	printf("Enter your choice :=> ");
	fflush(stdin);
	choice = getche();
	switch(choice){
		 case '1' : //call append record
			fillData();
			break;
		 case '2' : //call find record
			 findData();
			break;
		 case '3' : //Read all record
			showData();
			break;
		 case '4' : quit();
		 default  : exit(1);
	}
	  }
} // End of Code

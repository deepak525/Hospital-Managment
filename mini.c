#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct patient
{
	char date[20];
	char p_id[20];
	char name[20];
	char fname[20];
	char age[5];
	char sex[5];
	char category[20];
	char city[20];
	char mobile[20];
	char test[20];
	char bloodgroup[20];
	char diganosis[20];
	
}p;
struct doc
{
	char spe[20];
	char name[20];
	char avail[10];
	char mobile[10];
	char cabin[10];
}d;

 
 struct medicine
{
	char name[20];
	char rate[10];
	char quantity[10];
	
}m;

struct bill
{
	char id[20];
	char name[20];
	char age[20];
	char sex[5];
}b;
  

void main()
{
	printf("\t\t###################################################################################");
	printf("\t\t\t\t\t\t\t*****************@HOSPITAL MANAGEMENT@*********************");
	printf("\n\t\t###################################################################################");
    char name[20],name1[20],name2[20],ch,c,ch1;
    
	char pass[20],pass1[20]="helloguy",n1[20],spec[20];
	FILE *fp;
	FILE *ft;
	FILE *md;
	int i,j,a,f,s,d1,d2,n,n3,n2,c1,t,r,n4,t1,total=0,n5;
	f:printf("\n\t\t\t\t\t\tUSER NAME = ");
	gets(name);
	printf("\t\t\t\t\t\tpassword = ");
	for(i=0;i<strlen(pass1);i++)
	{
		c=getch();
		pass[i]=c;
		c='*';
		printf("%c",c);
	}
	pass[i]='\0';
	if(strcmp(name,"Deepak")==0 && strcmp(pass,pass1)==0)
	{
		printf("\n\t\t\t\t\t\tlogin successfully");
	}
	else
	{
		printf("\n\t\t\t\t\t\tinvalid user name or password");
		printf("\n\t\t\t\t\t\tTRY AGAIN!!!");
		goto f;
	}
	
	a:printf("\nplease choose a option");
	printf("\n1.Patient Ragistration form \n2.Doctor Registration \n3.Doctor Serch \n4.Patient Details \n5.Serch Patient \n6.Bill");
	printf("\nenter your option: ",c);
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\t\t\t\t@@@@@@@@@  PATIENT REGISTRATION  @@@@@@@@");
			    fp=fopen("patient.txt","a");
				printf("\nHOW Many Patient Details You Want To Fill: ");
				scanf("%d",&n);
				for(j=0;j<n;j++)
				{
					printf("\nEnter Details For Patient %d:",j+1);
					printf("\nDate: ");
					scanf("%s",&p.date);
					printf("Patient Id: ");
					fflush(stdin);
					scanf("%s",&p.p_id);
					printf("Patient Name: ");
					fflush(stdin);
					scanf("%s",&p.name);
					printf("Father's Name: ");
					fflush(stdin);
					scanf("%s",&p.fname);
					printf("Age: ");
					fflush(stdin);
					scanf("%s",&p.age);
					printf("Sex: ");
					fflush(stdin);
					scanf("%s",&p.sex);
					printf("Category: ");
					scanf("%s",&p.category);
					printf("City: ");
					fflush(stdin);
					scanf("%s",&p.city);
					printf("Mobile No.: ");
					fflush(stdin);
					scanf("%s",&p.mobile);
					printf("Test: ");
					fflush(stdin);
					scanf("%s",&p.test);
					printf("Bloodgroup: ");
					fflush(stdin);
					scanf("%s",&p.bloodgroup);
		            printf("Diganosis: ");
		            scanf("%s",&p.diganosis);
					fwrite(&p,sizeof(p),1,fp);
					fprintf(fp,"\n");
				}
				printf("\n\nwould you want to go back in main menu(1/0): ");
				scanf("%d",&c1);	
				if(c1==1)
				{
					goto a;
				}	
				else 
				break;
				fclose(fp);
		case 2:
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DOCTOR REGISTRATION>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			ft=fopen("doctor.txt","a");
			printf("ENTER NUMBER OF DOCTORS IN HOSPITAL:");
			scanf("%d",&n4);
			for(i=0;i<n4;i++)
			{
				printf("SPECIALITY:");
				scanf("%s",d.spe);
				fflush(stdin);
				printf("NAME:");
				scanf("%s",d.name);
			    fflush(stdin);
				printf("AVAILABLE AT :");
				scanf("%s",d.avail);
				fflush(stdin);
				printf("MOBILE NO.:");
				scanf("%s",d.mobile);
				fflush(stdin);
				printf("CABIN NO. :");
				scanf("%s",d.cabin);
				fflush(stdin);
				fwrite(&d,sizeof(d),1,ft);
			}
			fclose(ft);
			
			printf("\n\nwould you want to go back in main menu(1/0): ");
			scanf("%d",&c1);	
			if(c1==1)
			{
				goto a;
			}	
			else
			break;
			
		case 3:
			printf("\n\t\t<<<<<<<<<<<<<<<<DOCTOR RECORD>>>>>>>>>>>>>>>>>>>\n");
			t1:printf("ENTER DOCTOR YOU WANT TO SEARCH:");
			scanf("%s",spec);
			ft=fopen("doctor.txt","r");
										
			while(fread(&d,sizeof(d),1,ft)==1)
			{		
				if(strcmp(spec,d.spe)==0)
		    	{
		        	printf("SPEC          NAME     AVAILABILITY     MOBILE       CABIN NUMBER   ");
		    	    printf("\n%s       %s       %s        %s        %s ",d.spe,d.name,d.avail,d.mobile,d.cabin);
		    	}
		    	
			
			    /*else
			    {
			    	printf("!!!!!!!!!!!!DOCTOR NOT FOUND!!!!!!!!!!!!!!");
			    	printf("\t TRY AGAIN!!!");
			    	goto t1;
				}*/
		    }
		    printf("\nyou want to enquiry about another doctor(0/1): ");
		    scanf("%d",&n5);
		    if(n5==1)
		    {
		    	goto t1;
			}
			else
			{
		    	printf("\n\nwould you want to go back in main menu(1/0): ");
		     	scanf("%d",&c1);	
			    if(c1==1)
			       {
			        	goto a;
		        	}	
			    else
		     	break;
	
			}
			fclose(ft);
			break;
			
				
		
		case 4:
			printf("\n\t\t------------------------------------------------------------------------------");
		    printf("\n\t\t\t\t\t@@@@@@  PATIENT RECORD  @@@@@\n");
		    printf("\t\t------------------------------------------------------------------------------\n");
		    fp=fopen("patient.txt","r");
		    while(!feof(fp))
		    {
		    	ch=fgetc(fp);
		    	printf("%c",ch);
			}
			fclose(fp);
			printf("\n\nwould you want to go back in main menu(1/0): ");
			scanf("%d",&c1);	
			if(c1==1)			
			{
				goto a;
			}	
			else
			break;
		case 5:
			printf("\n\t\t@@@@@@  PATIENT SERCH  @@@@@\n");
		    r:fp=fopen("patient.txt","r");
		    printf("\nEnter Patient Name For Serch: ");
		    scanf("%s",&n1);
		    while(fread(&p,sizeof(p),1,fp)==1)
		    {
		    	if(strcmp(n1,p.name)==0)
		    	{
		    		printf("\nDate      Id    Name    FName    Age  Sex  Category  mobile     city  test    Bloodgroup  diaganosis");
		    		printf("\n%s  %s  %s  %s  %s   %s    %s      %s  %s  %s  %s          %s",p.date,p.p_id,p.name,p.fname,p.age,p.sex,p.category,p.mobile,p.city,p.test,p.bloodgroup,p.diganosis);
			        break;
				}
				
				else
				{
					printf("\nThis Name Doesn't Exist In Your List");
					printf("\tTry Again!!");
					goto r;
				}
			}
			printf("\n\nwould you want to go back in main menu(1/0): ");
			scanf("%d",&c1);	 
			if(c1==1)			
			{
				goto a;
			}	
			else
			break;
		
		case 6:
			printf("\nCHOOSE:\t\t");
			printf("\n1.GO TO MEDICINES\n2.TAKE BILL\n");
			printf("Choose OPtion: ");
			scanf("%d",&n3);
			switch(n3)
			{
               case 1:			
				printf("###################################################################################");
			    printf("\n\t\t\t                MEDICINES DEPARTMENT\n");
			    printf("###################################################################################\n");
		     	md=fopen("med.txt","a");
		    	printf("\nHOW MANY MEDICINES:");
		    	scanf("%d",&n2);
		    	for(i=0;i<n2;i++)
				{
					printf("\nENTER MEDICINE NAME:");
					scanf("%s",m.name);
					fflush(stdin);
					printf("ENTER RATE	 :");
					scanf("%s",m.rate);
					fflush(stdin);
					printf("ENTER QUANTITTY  :");
					scanf("%s",m.quantity);
					fflush(stdin);
				
					fwrite(&m,sizeof(m),1,md);
				}
				fclose(md);
				break;
				
			  case 2:
			  	printf("\n@@@@@@  Billing System  @@@@@");
		        printf("\n\tUni Hospital");
		        printf("\nBlock No.8,Jalandhar-Delhi G.T. Road(NH-1),Phagwara,Punjab");
		        printf("\nDate: 16-Nov-2016");
		        printf("\nPatient Id: "); 
		        scanf("%s",&b.id);
		        printf("Name: ");            
		        scanf("%s",&b.name);
		        printf("Sex: ");
		        scanf("%s",&b.sex);
	            printf("Age: ");
	            scanf("%s",b.age);
	            printf("====================================================================\n");
	
	           	printf("CHOOSE MEDICINE:");
			   	scanf("%s",&name2);
				md=fopen("med.txt","r");
				while(fread(&m,sizeof(m),1,md)==1)                         
				{
					if(strcmp(name2,m.name)==0)
	     		{
					printf("---------------------------------------------------------------------\n");
					printf("\nMEDICINE NAME    RATE    QUANTITY    \n");
					printf("---------------------------------------------------------------------\n");
					printf("  %s        %s             %s ",m.name,m.rate,m.quantity);
					total=total+atoi(m.rate)*atoi(m.quantity);	
				}	
				}
						printf("\n**********************************************************\n");	
						printf("GRAND TOTAL=%d",total);
						printf("\n**********************************************************\n");
		   }
	    
			  
	}
	
getch();
}

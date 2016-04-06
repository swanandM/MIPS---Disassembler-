#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char resister(char temp_rd1,char temp_rd2,char temp_rd3,char temp_rd4,char temp_rd5);
int immediate(char rd16,char rd17,char rd18,char rd19,char rd20,char rd21,char rd22,char rd23,char rd24,char rd25,char rd26,char rd27,char rd28,char rd29,char rd30,char rd31);
int jump(char jp6,char jp7,char jp8,char jp9,char jp10,char jp11,char jp12,char jp13,char jp14,char jp15,char jp16,char jp17,char jp18,char jp19,char jp20,char jp21,char jp22,char jp23,char jp24,char jp25,char jp26,char jp27,char jp28,char jp29,char jp30,char jp31);


//char immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	

int main() 
{
  int ss=2;
  int kk=3;
  char ch[10000];   
  char st[10000];
  char uno[1000];   // return from function
  char ox[10000];
  char funct[10000];
  char shamt[10000];
  char ref_shamt[5]={48,48,48,48,48};   //shamt
  char temp_shamt[5];  
  char rd[10000];
  //char temp_rd[5];
  char rt[10000];
  char temp_rt[5];
  char rs[10000];
  char temp_rs[5];
  char op[10000];
  char temp_op[5];
  char temp_break[10000];
  char temp[6];
  		//char op[6]={0,0,0,0,0,0};  //opcode
  		
       	char a[6]={49,48,48,48,48,48};  //add
       	char b[6]={49,48,48,48,48,49};  //addu
       	char c[6]={49,48,48,48,49,48};  //sub
       	char d[6]={49,48,48,48,49,49};  //subu
 	   	char e[6]={49,48,49,48,49,48};  //SLT
 	   	char f[6]={48,48,49,48,48,48};	//JR
 		char g[6]={48,48,48,48,48,48};	//NOP
 		char h[6]={49,48,48,49,48,48};  //AND
 		char jj[6]={49,48,48,49,49,48};	//XOR
 		char k[6]={49,48,48,49,49,49};	//NOR
 		char l[6]={48,48,48,48,48,48};	//SLL
 		char m[6]={48,48,48,48,49,48};	//SRL
 		char n[6]={48,48,48,48,49,49};	//SRA
 		char z1[6]={48,48,49,49,48,49};	//BREAK
 		char p[6]={49,48,48,49,48,49};  //OR
 		
 		
 	char ab[6]={48,48,48,48,48,48};	 //R type instruction.
 	char bb[6]={48,48,48,48,49,48};   //jump instruction
 	char q[6]={48,48,49,48,48,48};  //ADDI	
 	char r[6]={48,48,49,48,48,49};  //ADDIU
    char s[6]={48,48,49,48,49,48};  //SLTI
 	char t[6]={48,48,48,49,48,48};  //BEQ
 	char u[6]={48,48,48,49,48,49};  //BNE
 	char v[6]={48,48,48,48,48,49};  //BGEZ & BLTZ OFFSET CHECK
 	char w[6]={48,48,48,49,49,49};  //BGTZ
 	char x[6]={48,48,48,49,49,48};  //BLEZ
 	char y[6]={48,48,48,48,48};  //BLTZ
 	char yy[6]={48,48,48,48,49};  //BGEZ
 	char z[6]={49,48,49,48,49,49};  //SW
 	char aa[6]={49,48,48,48,49,49};  //LW
 	
 	
  char r0[5]={48,48,48,48,48};   //R0
  char r1[5]={48,48,48,48,49};   //R1
  char r2[5]={48,48,48,49,48};   //R2
  char r3[5]={48,48,48,49,49};   //R3      
  char r4[5]={48,48,49,48,48};   //R4
  char r5[5]={48,48,49,48,49};   //R5 
  char r6[5]={48,48,49,49,48};   //R6
  char r7[5]={48,48,49,49,49};   //R7
  char r8[5]={48,49,48,48,48};    //R8
  char r9[5]={48,49,48,48,49};     //R9
  char r10[5]={48,49,48,49,48};   //R10
  char r11[5]={48,49,48,49,49};   //R11
  char r12[5]={48,49,49,48,48};   //R12
  char r13[5]={48,49,49,48,49};   //R13
  char r14[5]={48,49,49,49,48};   //R14
  char r15[5]={48,49,49,49,49};   //R15
  char r16[5]={49,48,48,48,48};   //R16
  char r17[5]={49,48,48,48,49};   //R17
  char r18[5]={49,48,48,49,48};   //R18
  char r19[5]={49,48,48,49,49};   //R19
  char r20[5]={49,48,49,48,48};   //R20
  char r21[5]={49,48,49,48,49};   //R21
  char r22[5]={49,48,49,49,48};   //R22
  char r23[5]={49,48,49,49,49};   //R23
  char r24[5]={49,49,48,48,48};   //R24
  char r25[5]={49,49,48,48,49};   //R25
  char r26[5]={49,49,48,49,48};   //R26
  char r27[5]={49,49,48,49,49};   //R27
  char r28[5]={49,49,49,48,48};   //R28
  char r29[5]={49,49,49,48,49};   //R29
  char r30[5]={49,49,49,49,48};   //R30
  char r31[5]={49,49,49,49,49};   //R31
  
  
int test;
int test1;
int test2;
  
  FILE *you;
  FILE *my;
 
 	int end, loop;
  
	my = fopen("input.txt","r");
    if (my== NULL)
    {
    printf("can not open file \n");
    return 1;
    }
     
    you = fopen("output.txt","w");
	if (you== NULL)
    {
    printf("can not open file \n");
    return 1;
    } 
   /*
    int chh;
    int count;
    do
    {
 	  	chh = fgetc(my);
   		if( chh == '\n') count++;   
   	}while( chh != EOF );  
   
   printf("Total number of lines %d\n",count); 
   */
   
   int count;
   printf("Enter total number of binary inputs present in input.txt file : ");
    scanf("%d", &count);  
   
   
int address = 492;   
    
for(int line=1; line<=count;line++)

{
	
for(end = loop = 0;loop<line;++loop)
	{
        if(fgets(st, sizeof(st), my))
		{
            break;
        }
    }

printf("\n%s", st);


    printf("\n");
    printf("\n");
   // printf("\n%s", &st[0]);
    printf("\n");



for(int o=0;o<=31;o++)
	  {	
      	op[o]= st[o];
	  }

//fprintf(you,"\n%s", op);

 fprintf(you,"\n%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c %c%c%c%c%c%c  ",op[0],op[1],op[2],op[3],op[4],op[5],op[6],op[7],op[8],op[9],op[10],op[11],op[12],op[13],op[14],op[15],op[16],op[17],op[18],op[19],op[20],op[21],op[22],op[23],op[24],op[25],op[26],op[27],op[28],op[29],op[30],op[31]);

	temp_break[0]=op[0];
  	temp_break[1]=op[1];
  	temp_break[2]=op[2];
  	temp_break[3]=op[3];
  	temp_break[4]=op[4];
  	temp_break[5]=op[5];
  	temp_break[6]=op[6];
  	temp_break[7]=op[7];
  	temp_break[8]=op[8];
  	temp_break[9]=op[9];
  	temp_break[10]=op[10];
  	temp_break[11]=op[11];
  	temp_break[12]=op[12];
  	temp_break[13]=op[13];
  	temp_break[14]=op[14];
  	temp_break[15]=op[15];
  	temp_break[16]=op[16];
  	temp_break[17]=op[17];
  	temp_break[18]=op[18];
  	temp_break[19]=op[19];
  	temp_break[20]=op[20];
  	temp_break[21]=op[21];
  	temp_break[22]=op[22];
  	temp_break[23]=op[23];
  	temp_break[24]=op[24];
  	temp_break[25]=op[25];
  	temp_break[26]=op[26];
  	temp_break[27]=op[27];
  	temp_break[28]=op[28];
  	temp_break[29]=op[29];
	temp_break[30]=op[30];
  	temp_break[31]=op[31];
  	
fprintf(you,"\t");
address = address + 4;
fprintf(you,"%d",address); 

///////////////////////OPCODE//////////////////

 	  for(int o=0;o<=5;o++)
	  {	
      	op[o]= st[o];
		printf("%s", &op[o]);  // print 0-5 bits.
	  }
	printf("\n");
	
	temp_op[0]=op[0];
  	temp_op[1]=op[1];
  	temp_op[2]=op[2];
  	temp_op[3]=op[3];
  	temp_op[4]=op[4];
  	temp_op[5]=op[5];
  		
/////////////////////end of opcode////////////////////////////

	 if(temp_break[0]==g[0] && temp_break[1]==g[1] && temp_break[2]==g[2] && temp_break[3]==g[3] && temp_break[4]==g[4] && temp_break[5]==g[5] && temp_break[31]==g[0] && temp_break[30]==g[1] && temp_break[29]==g[2] && temp_break[28]==g[3] && temp_break[27]==g[4] && temp_break[26]==g[5])
		{
			printf("\n");
			printf("this is NOP instruction");	
			fprintf(you,"\t%s\t","NOP");
			//return 0;
		}

	else if(temp_break[0]==g[0] && temp_break[1]==g[1] && temp_break[2]==g[2] && temp_break[3]==g[3] && temp_break[4]==g[4] && temp_break[5]==g[5] && temp_break[26]==z1[0] && temp_break[27]==z1[1] && temp_break[28]==z1[2] && temp_break[29]==z1[3] && temp_break[30]==z1[4] && temp_break[31]==z1[5] )
		{
			printf("\n");
			printf("this is BREAK instruction");
			fprintf(you,"\t%s\t","BREAK");
			return 0;	
		}
	else if(temp_break[0]==g[0] && temp_break[1]==g[1] && temp_break[2]==g[2] && temp_break[3]==g[3] && temp_break[4]==g[4] && temp_break[5]==g[5] && temp_break[26]==f[0] && temp_break[27]==f[1] && temp_break[28]==f[2] && temp_break[29]==f[3] && temp_break[30]==f[4] && temp_break[31]==f[5] )   // jump register instruction
		{
			printf("\n");
			printf("this is JUMP REGISTER instruction");  
			printf("\n"); 
			fprintf(you,"\t%s\t","JR");
	      for(int n=6;n<=10;n++)
		  {	
	      	rs[n]= st[n];
			printf("%s", &rs[n]);  // print 6-10 bits.
		  }
		  resister(rs[6],rs[7],rs[8],rs[9],rs[10]); 
		  printf("\n");
		  
			//return 0;
		}	
	else if(temp_break[0]==g[0] && temp_break[1]==g[1] && temp_break[2]==g[2] && temp_break[3]==g[3] && temp_break[4]==g[4] && temp_break[5]==g[5] && temp_break[6]==g[0] && temp_break[7]==g[1] && temp_break[8]==g[2] && temp_break[9]==g[3] && temp_break[10]==g[4]  && temp_break[26]==l[0] && temp_break[27]==l[1] && temp_break[28]==l[2] && temp_break[29]==l[3] && temp_break[30]==l[4] && temp_break[31]==l[5] )
		{
			printf("\n");
			printf("this is SLL instruction");	
			fprintf(you,"\t%s\t","SLL");
			
			      for(int l=16;l<=20;l++)
				  {	
			      	rd[l]= st[l];
					printf("%s", &rd[l]);  // print 16-20 bits.
				  }
			
				 
			test = resister(rd[16],rd[17],rd[18],rd[19],rd[20]);
			fprintf(you,"  ,R%d", test);
				
				printf("\n");
					 
				 for(int n=21;n<=25;n++)
				  {	
			      	rs[n]= st[n];
					printf("%s", &rs[n]);  // print 6-10 bits.
				  }
				  
					 	 
			test=resister(rs[21],rs[22],rs[23],rs[24],rs[25]);
			fprintf(you,"  ,R%d", test);
			
				printf("\n");	  
					  	  
				   for(int m=11;m<=15;m++)
				  {	
			      	rt[m]= st[m];
					printf("%s", &rt[m]);  // print 11-15 bits.
				  }
				
			test=resister(rt[11],rt[12],rt[13],rt[14],rt[15]);
			fprintf(you,"  ,R%d", test);
			
		}

////////////////////////////////////////////////////////////////////////////////////////////  
else if (temp_op[0]==ab[0] && temp_op[1]==ab[1] && temp_op[2]==ab[2] && temp_op[3]==ab[3] && temp_op[4]==ab[4] && temp_op[5]==ab[5] )

{
	
 
  /////////////////////////////last field FUNCTION///////////////////
	  for(int j=26;j<=31;j++)
	  {	
      	funct[j]= st[j];
		printf("%s", &funct[j]);  //print 26-31 bits
	  }		  
			  
	temp[0]=funct[26];
	temp[1]=funct[27];
	temp[2]=funct[28];
	temp[3]=funct[29];
	temp[4]=funct[30];
	temp[5]=funct[31];

	
		if(temp[0]==a[0] && temp[1]==a[1] && temp[2]==a[2] && temp[3]==a[3] && temp[4]==a[4] && temp[5]==a[5] )
		{  
			printf("\n");
			printf("this is ADD instruction");
			fprintf(you,"\t%s\t","ADD");
		} 
		else if(temp[0]==b[0] && temp[1]==b[1] && temp[2]==b[2] && temp[3]==b[3] && temp[4]==b[4] && temp[5]==b[5] )
		{
			printf("\n");
			printf("this is ADDU instruction");	
			fprintf(you,"\t%s\t","ADDU");
		}
		else if(temp[0]==c[0] && temp[1]==c[1] && temp[2]==c[2] && temp[3]==c[3] && temp[4]==c[4] && temp[5]==c[5] )
		{
			printf("\n");
			printf("this is SUB instruction");	
			fprintf(you,"\t%s\t","SUB");
		}
		else if(temp[0]==d[0] && temp[1]==d[1] && temp[2]==d[2] && temp[3]==d[3] && temp[4]==d[4] && temp[5]==d[5] )
		{
			printf("\n");
			printf("this is SUBU instruction");	
			fprintf(you,"\t%s\t","SUBU");
		}
		else if(temp[0]==e[0] && temp[1]==e[1] && temp[2]==e[2] && temp[3]==e[3] && temp[4]==e[4] && temp[5]==e[5] )
		{
			printf("\n");
			printf("this is SLT instruction");
			fprintf(you,"\t%s\t","SLT");	
		}
		
		else if(temp[0]==h[0] && temp[1]==h[1] && temp[2]==h[2] && temp[3]==h[3] && temp[4]==h[4] && temp[5]==h[5] )
		{
			printf("\n");
			printf("this is AND instruction");
			fprintf(you,"\t%s\t","AND");	
		}
		else if(temp[0]==p[0] && temp[1]==p[1] && temp[2]==p[2] && temp[3]==p[3] && temp[4]==p[4] && temp[5]==p[5] )
		{
			printf("\n");
			printf("this is OR instruction");
			fprintf(you,"\t%s\t","OR");	
		}
		else if(temp[0]==jj[0] && temp[1]==jj[1] && temp[2]==jj[2] && temp[3]==jj[3] && temp[4]==jj[4] && temp[5]==jj[5] )
		{
			printf("\n");
			printf("this is XOR instruction");
			fprintf(you,"\t%s\t","XOR");	
		}
		else if(temp[0]==k[0] && temp[1]==k[1] && temp[2]==k[2] && temp[3]==k[3] && temp[4]==k[4] && temp[5]==k[5] )
		{
			printf("\n");
			printf("this is NOR instruction");
			fprintf(you,"\t%s\t","NOR");	
		}
				
		else if(temp[0]==m[0] && temp[1]==m[1] && temp[2]==m[2] && temp[3]==m[3] && temp[4]==m[4] && temp[5]==m[5] )
		{
			printf("\n");
			printf("this is SRL instruction");
			fprintf(you,"\t%s\t","SRL");	
		}
		else if(temp[0]==n[0] && temp[1]==n[1] && temp[2]==n[2] && temp[3]==n[3] && temp[4]==n[4] && temp[5]==n[5] )
		{
			printf("\n");
			printf("this is SRA instruction");
			fprintf(you,"\t%s\t","SRA");	
		}	
		else
		{
			printf("none of the above");
		}

	  printf("\n");
	  
      for(int l=16;l<=20;l++)
	  {	
      	rd[l]= st[l];
		printf("%s", &rd[l]);  // print 16-20 bits.
	  }

	 
test = resister(rd[16],rd[17],rd[18],rd[19],rd[20]);
fprintf(you,"  ,R%d", test);
	
	printf("\n");
		 
	 for(int n=6;n<=10;n++)
	  {	
      	rs[n]= st[n];
		printf("%s", &rs[n]);  // print 6-10 bits.
	  }
	  
		 	 
test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);
fprintf(you,"  ,R%d", test);

	printf("\n");	  
		  	  
	   for(int m=11;m<=15;m++)
	  {	
      	rt[m]= st[m];
		printf("%s", &rt[m]);  // print 11-15 bits.
	  }
	
test=resister(rt[11],rt[12],rt[13],rt[14],rt[15]);
fprintf(you,"  ,R%d", test);

}

///////////////////////////////////////////////////////////////////////////////

	
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////immideate//////////////////////////////////////////////

else if(temp_op[0]==v[0] && temp_op[1]==v[1] && temp_op[2]==v[2] && temp_op[3]==v[3] && temp_op[4]==v[4] && temp_op[5]==v[5] )
{
		for(int l=11;l<=15;l++)
		 {	
	      	rd[l]= st[l];
			printf("%s", &rd[l]);  // print 16-20 bits.
		}
	 				
		if (rd[11]==yy[0] && rd[12]==yy[1] && rd[13]==yy[2] && rd[14]==yy[3] && rd[15]==yy[4] ) 
		{  
					printf("\n");
					printf("this is BGEZ instruction");
					fprintf(you,"\t%s\t","BGEZ");
					printf("\n");
					
				for(int n=6;n<=10;n++)
				  {	
			      	rs[n]= st[n];
					printf("%s", &rs[n]);  // print 6-10 bits.
				  }
			  		 	 
			test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);
			fprintf(you,"  ,R%d", test);
				
				printf("\n");
			
				 for(int l=16;l<=31;l++)
				  {	
			      	rd[l]= st[l];
					printf("%s", &rd[l]);  // print 16-31 bits.
				//	fprintf(you,"\t%s",&rd[l]);
				  }
		
			test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	
			if(rd[16]=='1')
			{
			fprintf(you,"  ,#-%d", test1);
			}
			else	
			{
			fprintf(you,"  ,#%d", test1);
			}	

			
		} 
	
else if (rd[11]==y[0] && rd[12]==y[1] && rd[13]==y[2] && rd[14]==y[3] && rd[15]==y[4])
		{  
					printf("\n");
					printf("this is BLTZ instruction");
					fprintf(you,"\t%s\t","BLTZ");
					printf("\n");
					
				for(int n=6;n<=10;n++)
				  {	
			      	rs[n]= st[n];
					printf("%s", &rs[n]);  // print 6-10 bits.
				  }
			  		 	 
			test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);
			fprintf(you,"  ,R%d", test);
			
				printf("\n");
			
				 for(int l=16;l<=31;l++)
				  {	
			      	rd[l]= st[l];
					printf("%s", &rd[l]);  // print 16-31 bits.
				//	fprintf(you,"\t%s",&rd[l]);
				  }
		
			test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	
			if(rd[16]=='1')
			{
			fprintf(you,"  ,#-%d", test1);
			}
			else	
			{
			fprintf(you,"  ,#%d", test1);
			}	
			
		}
else
		{
			printf("none of the above 1234");
		}

}
//////////////////////////////////////////////////////////////////////////////////////

else if(temp_op[0]==w[0] && temp_op[1]==w[1] && temp_op[2]==w[2] && temp_op[3]==w[3] && temp_op[4]==w[4] && temp_op[5]==w[5] )
{  
			//printf("\n");
			printf("this is BGTZ instruction");
			fprintf(you,"\t%s\t","BGTZ");
	
		printf("\n");
		for(int n=6;n<=10;n++)
		  {	
	      	rs[n]= st[n];
			printf("%s", &rs[n]);  // print 6-10 bits.
		  }
	  		 
		test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);
		fprintf(you,"  ,%d", test);	
	
		printf("\n");
		 for(int l=16;l<=31;l++)
		  {	
	      	rd[l]= st[l];
			printf("%s", &rd[l]);  // print 16-31 bits.
		
		  }
	
		test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	
		if(rd[16]=='1')
		{
		fprintf(you,"  ,#-%d", test1);
		}
		else	
		{
		fprintf(you,"  ,#%d", test1);
		}	

} 

else if(temp_op[0]==x[0] && temp_op[1]==x[1] && temp_op[2]==x[2] && temp_op[3]==x[3] && temp_op[4]==x[4] && temp_op[5]==x[5] )
{  
			printf("\n");
			printf("this is BLEZ instruction");
			fprintf(you,"\t%s\t","BLEZ");
			printf("\n");
		for(int n=6;n<=10;n++)
		  {	
	      	rs[n]= st[n];
			printf("%s", &rs[n]);  // print 6-10 bits.
		  }
	  		 	 
		test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);
		fprintf(you,"  ,R%d", test);
		
			printf("\n");	
		 for(int l=16;l<=31;l++)
		  {	
	      	rd[l]= st[l];
			printf("%s", &rd[l]);  // print 16-31 bits.
		//	fprintf(you,"\t%s",&rd[l]);
		  }

		test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	
		if(rd[16]=='1')
		{
		fprintf(you,"  ,#-%d", test1);
		}
		else	
		{
		fprintf(you,"  ,#%d", test1);
		}	
	
}

///////////////////////////////////////JUMP////////////////////////////////////////////////


else if(temp_op[0]==bb[0] && temp_op[1]==bb[1] && temp_op[2]==bb[2] && temp_op[3]==bb[3] && temp_op[4]==bb[4] && temp_op[5]==bb[5])  // jump 
	{
		printf("this is JUMP instruction");  
		printf("\n"); 
		fprintf(you,"\t%s\t","J");
      for(int l=6;l<=31;l++)
	  {	
      	rd[l]= st[l];
		printf("%s", &rd[l]);  // print 6-31 bits.
		//fprintf(you,"\t%s",&rd[l]);
	  }
	  test2=jump(rd[6],rd[7],rd[8],rd[9],rd[10],rd[11],rd[12],rd[13],rd[14],rd[15],rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);
		fprintf(you,"  ,#%d", test2);	
		
		printf("\n");
	
	}

else if(temp_op[0]==z[0] && temp_op[1]==z[1] && temp_op[2]==z[2] && temp_op[3]==z[3] && temp_op[4]==z[4] && temp_op[5]==z[5] )
{  
			printf("\n");
			printf("this is SW instruction");
			fprintf(you,"\t%s\t","SW");
		
		
	   for(int m=11;m<=15;m++)
	  {	
      	rt[m]= st[m];
		printf("%s", &rt[m]);  // print 11-15 bits.
	  }
 
	test=resister(rt[11],rt[12],rt[13],rt[14],rt[15]);
	fprintf(you,"  ,R%d", test);

	printf("\n");
   for(int l=16;l<=31;l++)
	  {	
      	rd[l]= st[l];
		printf("%s", &rd[l]);  // print 16-31 bits.
	  }

	test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);		
		fprintf(you,"  ,%d", test1);
		


 	printf("\n");
	  for(int n=6;n<=10;n++)
	  {	
      	rs[n]= st[n];
		printf("%s", &rs[n]);  // print 6-10 bits.	
	  }
				
	test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);	
	fprintf(you,"(R%d)", test);

}


		
else if(temp_op[0]==aa[0] && temp_op[1]==aa[1] && temp_op[2]==aa[2] && temp_op[3]==aa[3] && temp_op[4]==aa[4] && temp_op[5]==aa[5] )
		{  
			printf("\n");
			printf("this is LW instruction");
			fprintf(you,"\t%s\t","LW");
			
					  for(int m=11;m<=15;m++)
			  {	
		      	rt[m]= st[m];
				printf("%s", &rt[m]);  // print 11-15 bits.
			  }
		 
			test=resister(rt[11],rt[12],rt[13],rt[14],rt[15]);
			fprintf(you,"  ,R%d", test);
		
			printf("\n");
		   for(int l=16;l<=31;l++)
			  {	
		      	rd[l]= st[l];
				printf("%s", &rd[l]);  // print 16-31 bits.
			  }
		
			test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);			
			fprintf(you,"  ,%d", test1);
			

		
		 	printf("\n");
			  for(int n=6;n<=10;n++)
			  {	
		      	rs[n]= st[n];
				printf("%s", &rs[n]);  // print 6-10 bits.	
			  }
						
			test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);	
			fprintf(you,"(R%d)", test);
			
		}

else  
{	
  		 if(temp_op[0]==q[0] && temp_op[1]==q[1] && temp_op[2]==q[2] && temp_op[3]==q[3] && temp_op[4]==q[4] && temp_op[5]==q[5] )
		{  
			printf("\n");
			printf("this is ADDI instruction");
			fprintf(you,"\t%s\t","ADDI");
		} 
		else if(temp_op[0]==r[0] && temp_op[1]==r[1] && temp_op[2]==r[2] && temp_op[3]==r[3] && temp_op[4]==r[4] && temp_op[5]==r[5] )
		{  
			printf("\n");
			printf("this is ADDIV instruction");
			fprintf(you,"\t%s\t","ADDIV");
		}
		else if(temp_op[0]==s[0] && temp_op[1]==s[1] && temp_op[2]==s[2] && temp_op[3]==s[3] && temp_op[4]==s[4] && temp_op[5]==s[5] )
		{  
			printf("\n");
			printf("this is SLTI instruction");
			fprintf(you,"\t%s\t","SLTI");
		} 
		else if(temp_op[0]==t[0] && temp_op[1]==t[1] && temp_op[2]==t[2] && temp_op[3]==t[3] && temp_op[4]==t[4] && temp_op[5]==t[5] )
		{  
			printf("\n");
			printf("this is BEQ instruction");
			fprintf(you,"\t%s\t","BEQ");
		} 
		else if(temp_op[0]==u[0] && temp_op[1]==u[1] && temp_op[2]==u[2] && temp_op[3]==u[3] && temp_op[4]==u[4] && temp_op[5]==u[5] )
		{  
			printf("\n");
			printf("this is BNE instruction");
			fprintf(you,"\t%s\t","BNE");
		} 
		else
		{
			printf("none of the above 1234");
		}
  		printf("\n");

	   for(int m=11;m<=15;m++)
	  {	
      	rt[m]= st[m];
		printf("%s", &rt[m]);  // print 11-15 bits.
	  }
 
test=resister(rt[11],rt[12],rt[13],rt[14],rt[15]);
fprintf(you,"  ,R%d", test);

 	printf("\n");

	 
	  for(int n=6;n<=10;n++)
	  {	
      	rs[n]= st[n];
		printf("%s", &rs[n]);  // print 6-10 bits.	
	  }
				
test=resister(rs[6],rs[7],rs[8],rs[9],rs[10]);	
fprintf(you,"  ,R%d", test);

	printf("\n");
		   			   
      for(int l=16;l<=31;l++)
	  {	
      	rd[l]= st[l];
		printf("%s", &rd[l]);  // print 16-31 bits.
	//	fprintf(you,"\t%s",&rd[l]);
	  }

	test1=immediate(rd[16],rd[17],rd[18],rd[19],rd[20],rd[21],rd[22],rd[23],rd[24],rd[25],rd[26],rd[27],rd[28],rd[29],rd[30],rd[31]);	
		if(rd[16]=='1')
		{
		fprintf(you,"  ,#-%d", test1);
		}
		else	
		{
		fprintf(you,"  ,#%d", test1);
		}	
	
}
//line++;
}
	//	my.close();
   //fclose(my);
//}
    return 0;
}


char resister(char temp_rd1,char temp_rd2,char temp_rd3,char temp_rd4,char temp_rd5)
{
 char temp_rd[5];
	int n;
 
 FILE *you;
 //you = fopen("test2.txt","a");
 
  
//fprintf(youu,"\v%s",",");
 
// fprintf(you,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%s",",");
 
  char r0[5]={48,48,48,48,48};   //R0
  char r1[5]={48,48,48,48,49};   //R1
  char r2[5]={48,48,48,49,48};   //R2
  char r3[5]={48,48,48,49,49};   //R3      
  char r4[5]={48,48,49,48,48};   //R4
  char r5[5]={48,48,49,48,49};   //R5 
  char r6[5]={48,48,49,49,48};   //R6
  char r7[5]={48,48,49,49,49};   //R7
  char r8[5]={48,49,48,48,48};    //R8
  char r9[5]={48,49,48,48,49};     //R9
  char r10[5]={48,49,48,49,48};   //R10
  char r11[5]={48,49,48,49,49};   //R11
  char r12[5]={48,49,49,48,48};   //R12
  char r13[5]={48,49,49,48,49};   //R13
  char r14[5]={48,49,49,49,48};   //R14
  char r15[5]={48,49,49,49,49};   //R15
  char r16[5]={49,48,48,48,48};   //R16
  char r17[5]={49,48,48,48,49};   //R17
  char r18[5]={49,48,48,49,48};   //R18
  char r19[5]={49,48,48,49,49};   //R19
  char r20[5]={49,48,49,48,48};   //R20
  char r21[5]={49,48,49,48,49};   //R21
  char r22[5]={49,48,49,49,48};   //R22
  char r23[5]={49,48,49,49,49};   //R23
  char r24[5]={49,49,48,48,48};   //R24
  char r25[5]={49,49,48,48,49};   //R25
  char r26[5]={49,49,48,49,48};   //R26
  char r27[5]={49,49,48,49,49};   //R27
  char r28[5]={49,49,49,48,48};   //R28
  char r29[5]={49,49,49,48,49};   //R29
  char r30[5]={49,49,49,49,48};   //R30
  char r31[5]={49,49,49,49,49};   //R31
  

		temp_rd[0]=temp_rd1;
	  	temp_rd[1]=temp_rd2;
	  	temp_rd[2]=temp_rd3;
	  	temp_rd[3]=temp_rd4;
	  	temp_rd[4]=temp_rd5;


	if(temp_rd[0]==r0[0] && temp_rd[1]==r0[1] && temp_rd[2]==r0[2] && temp_rd[3]==r0[3] && temp_rd[4]==r0[4]  )
		{  
			printf("\n");
			printf("this is R0");
			//fprintf(you,"%s"," ,R0");
			n=0;
			return n;
		} 
		else if(temp_rd[0]==r1[0] && temp_rd[1]==r1[1] && temp_rd[2]==r1[2] && temp_rd[3]==r1[3] && temp_rd[4]==r1[4] )
		{
			printf("\n");
			printf("this is R1");
			//fprintf(you,"%s"," ,R1");
			n=1;
			return n;
		
		} 
		else if(temp_rd[0]==r2[0] && temp_rd[1]==r2[1] && temp_rd[2]==r2[2] && temp_rd[3]==r2[3] && temp_rd[4]==r2[4] )
		{
			printf("\n");
			printf("this is R2");
			//fprintf(you,"%s"," ,R2");
			n=2;
			return n;
		} 
		else if(temp_rd[0]==r3[0] && temp_rd[1]==r3[1] && temp_rd[2]==r3[2] && temp_rd[3]==r3[3] && temp_rd[4]==r3[4] )
		{
			printf("\n");
			printf("this is R3");
			//fprintf(you,"%s"," ,R3");
			n=3;
			return n;		
		
		}  
		else if(temp_rd[0]==r4[0] && temp_rd[1]==r4[1] && temp_rd[2]==r4[2] && temp_rd[3]==r4[3] && temp_rd[4]==r4[4] )
		{
			printf("\n");
			printf("this is R4");
			//fprintf(you,"%s"," ,R4");
			n=4;
			return n;
		
		} 
		else if (temp_rd[0]==r5[0] && temp_rd[1]==r5[1] && temp_rd[2]==r5[2] && temp_rd[3]==r5[3] && temp_rd[4]==r5[4] )
		{
			printf("\n");
			printf("this is R5");
			//fprintf(you,"%s"," ,R5");
			n=5;
			return n;
		
		} 
		else if (temp_rd[0]==r6[0] && temp_rd[1]==r6[1] && temp_rd[2]==r6[2] && temp_rd[3]==r6[3] && temp_rd[4]==r6[4] )
		{
			printf("\n");
			printf("this is R6");
			//fprintf(you,"%s"," ,R6");
			n=6;
			return n;
		
		} 
		else if (temp_rd[0]==r7[0] && temp_rd[1]==r7[1] && temp_rd[2]==r7[2] && temp_rd[3]==r7[3] && temp_rd[4]==r7[4] )
		{
			printf("\n");
			printf("this is R7");
			//fprintf(you,"%s"," ,R7");
			n=7;
			return n;
		
		} 
		else if (temp_rd[0]==r8[0] && temp_rd[1]==r8[1] && temp_rd[2]==r8[2] && temp_rd[3]==r8[3] && temp_rd[4]==r8[4] )
		{
			printf("\n");
			printf("this is R8");
			//fprintf(you,"%s"," ,R8");
			n=8;
			return n;
		} 
		else if (temp_rd[0]==r9[0] && temp_rd[1]==r9[1] && temp_rd[2]==r9[2] && temp_rd[3]==r9[3] && temp_rd[4]==r9[4] )
		{
			printf("\n");
			printf("this is R9");
			//fprintf(you,"%s"," ,R9");
			n=9;
			return n;
		} 
		else if (temp_rd[0]==r10[0] && temp_rd[1]==r10[1] && temp_rd[2]==r10[2] && temp_rd[3]==r10[3] && temp_rd[4]==r10[4] )
		{
			printf("\n");
			printf("this is R10");
			//fprintf(you,"%s"," ,R10");
			n=10;
			return n;
		
		} 
		else if (temp_rd[0]==r11[0] && temp_rd[1]==r11[1] && temp_rd[2]==r11[2] && temp_rd[3]==r11[3] && temp_rd[4]==r11[4] )
		{
			printf("\n");
			printf("this is R11");
			//fprintf(you,"%s"," ,R11");
			n=11;
			return n;
		} 
		else if (temp_rd[0]==r12[0] && temp_rd[1]==r12[1] && temp_rd[2]==r12[2] && temp_rd[3]==r12[3] && temp_rd[4]==r12[4] )
		{
			printf("\n");
			printf("this is R12");
			//fprintf(you,"%s"," ,R12");
			n=12;
			return n;
		}
		 else if (temp_rd[0]==r13[0] && temp_rd[1]==r13[1] && temp_rd[2]==r13[2] && temp_rd[3]==r13[3] && temp_rd[4]==r13[4] )
		{
			printf("\n");
			printf("this is R13");
			//fprintf(you,"%s"," ,R13");
			n=13;
			return n;
		}
		 else if (temp_rd[0]==r14[0] && temp_rd[1]==r14[1] && temp_rd[2]==r14[2] && temp_rd[3]==r14[3] && temp_rd[4]==r14[4] )
		{
			printf("\n");
			printf("this is R14");
			//fprintf(you,"%s"," ,R14");
			n=14;
			return n;
		} 
		else if (temp_rd[0]==r15[0] && temp_rd[1]==r15[1] && temp_rd[2]==r15[2] && temp_rd[3]==r15[3] && temp_rd[4]==r15[4] )
		{
			printf("\n");
			printf("this is R15");
			//fprintf(you,"%s"," ,R15");
			n=15;
			return n;
		} 
		else if (temp_rd[0]==r16[0] && temp_rd[1]==r16[1] && temp_rd[2]==r16[2] && temp_rd[3]==r16[3] && temp_rd[4]==r16[4] )
		{
			printf("\n");
			printf("this is R16");
			//fprintf(you,"%s"," ,R16");
			n=16;
			return n;
		} 
		else if (temp_rd[0]==r17[0] && temp_rd[1]==r17[1] && temp_rd[2]==r17[2] && temp_rd[3]==r17[3] && temp_rd[4]==r17[4] )
		{
			printf("\n");
			printf("this is R17");
			//fprintf(you,"%s"," ,R17");
			n=17;
			return n;
		} 
		else if (temp_rd[0]==r18[0] && temp_rd[1]==r18[1] && temp_rd[2]==r18[2] && temp_rd[3]==r18[3] && temp_rd[4]==r18[4] )
		{
			printf("\n");
			printf("this is R18");
			//fprintf(you,"%s"," ,R18");
			n=18;
			return n;
		} 
		else if (temp_rd[0]==r19[0] && temp_rd[1]==r19[1] && temp_rd[2]==r19[2] && temp_rd[3]==r19[3] && temp_rd[4]==r19[4] )
		{
			printf("\n");
			printf("this is R19");
			//fprintf(you,"%s"," ,R19");
			n=19;
			return n;
		} 
		else if (temp_rd[0]==r20[0] && temp_rd[1]==r20[1] && temp_rd[2]==r20[2] && temp_rd[3]==r20[3] && temp_rd[4]==r20[4] )
		{
			printf("\n");
			printf("this is R20");
			//fprintf(you,"%s"," ,R20");
			n=20;
			return n;
		} 
		else if (temp_rd[0]==r21[0] && temp_rd[1]==r21[1] && temp_rd[2]==r21[2] && temp_rd[3]==r21[3] && temp_rd[4]==r21[4] )
		{
			printf("\n");
			printf("this is R21");
			//fprintf(you,"%s"," ,R21");
			n=21;
			return n;
		} 
		else if (temp_rd[0]==r22[0] && temp_rd[1]==r22[1] && temp_rd[2]==r22[2] && temp_rd[3]==r22[3] && temp_rd[4]==r22[4] )
		{
			printf("\n");
			printf("this is R22");
			//fprintf(you,"%s"," ,R22");
			n=22;
			return n;
		} 
		else if (temp_rd[0]==r23[0] && temp_rd[1]==r23[1] && temp_rd[2]==r23[2] && temp_rd[3]==r23[3] && temp_rd[4]==r23[4] )
		{
			printf("\n");
			printf("this is R23");
			//fprintf(you,"%s"," ,R23");
			n=23;
			return n;
		} 
		else if (temp_rd[0]==r24[0] && temp_rd[1]==r24[1] && temp_rd[2]==r24[2] && temp_rd[3]==r24[3] && temp_rd[4]==r24[4] )
		{
			printf("\n");
			printf("this is R24");
			//fprintf(you,"%s"," ,R24");
			n=24;
			return n;
		} 
		else if (temp_rd[0]==r25[0] && temp_rd[1]==r25[1] && temp_rd[2]==r25[2] && temp_rd[3]==r25[3] && temp_rd[4]==r25[4] )
		{
			printf("\n");
			printf("this is R25");
			//fprintf(you,"%s"," ,R25");
			n=25;
			return n;
		} 
		else if (temp_rd[0]==r26[0] && temp_rd[1]==r26[1] && temp_rd[2]==r26[2] && temp_rd[3]==r26[3] && temp_rd[4]==r26[4] )
		{
			printf("\n");
			printf("this is R26");
			//fprintf(you,"%s"," ,R26");
			n=26;
			return n;
		} 
		else if (temp_rd[0]==r27[0] && temp_rd[1]==r27[1] && temp_rd[2]==r27[2] && temp_rd[3]==r27[3] && temp_rd[4]==r27[4] )
		{
			printf("\n");
			printf("this is R27");
			//fprintf(you,"%s"," ,R27");
			n=27;
			return n;
		} 
		else if (temp_rd[0]==r28[0] && temp_rd[1]==r28[1] && temp_rd[2]==r28[2] && temp_rd[3]==r28[3] && temp_rd[4]==r28[4] )
		{
			printf("\n");
			printf("this is R28");
			//fprintf(you,"%s"," ,R28");
			n=28;
			return n;
		} 
		else if (temp_rd[0]==r29[0] && temp_rd[1]==r29[1] && temp_rd[2]==r29[2] && temp_rd[3]==r29[3] && temp_rd[4]==r29[4] )
		{
			printf("\n");
			printf("this is R29");
			//fprintf(you,"%s"," ,R29");
			n=29;
			return n;
		} 
		else if (temp_rd[0]==r30[0] && temp_rd[1]==r30[1] && temp_rd[2]==r30[2] && temp_rd[3]==r30[3] && temp_rd[4]==r30[4] )
		{
			printf("\n");
			printf("this is R30");
			//fprintf(you,"%s"," ,R30");
			n=30;
			return n;
		} 
		else if (temp_rd[0]==r31[0] && temp_rd[1]==r31[1] && temp_rd[2]==r31[2] && temp_rd[3]==r31[3] && temp_rd[4]==r31[4] )
		{
			printf("\n");
			printf("this is R31");
			//fprintf(you,"%s"," ,R31");
			n=31;
			return n;
		} 
		else 
		{
			printf("\n");
			printf("something else");
			fprintf(you,"\n%s","something else");
		}

//fclose(you);
}

/////////////////////////////////immediate////////////////////////////

int immediate(char rd16,char rd17,char rd18,char rd19,char rd20,char rd21,char rd22,char rd23,char rd24,char rd25,char rd26,char rd27,char rd28,char rd29,char rd30,char rd31)
{
	
FILE *you;
//you = fopen("test2.txt","a");	

int add=0;

if (rd16=='1')
{
	
		if (rd16== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 32768;
		}	
		if (rd17== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 16384;
		}
		if (rd18== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 8192;
		}
		if (rd19== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 4096;
		}
		if (rd20== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 2048;
		}
		if (rd21== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 1024;
		}
		if (rd22== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 512;
		}
		if (rd23== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 256;
		}
		if (rd24=='1')
		{
			add = add + 0;
		}else
		{
			add = add + 128;
		}
		if (rd25=='1')
		{
			add = add + 0;
		}else
		{
			add = add + 64;
		}
		if (rd26== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 32;
		}
		if (rd27== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 16;
		}
		if (rd28== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 8;
		}
		if (rd29== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 4;
		}
		if (rd30== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 2;
		}
		if (rd31== '1')
		{
			add = add + 0;
		}else
		{
			add = add + 1;
		}
		
add = add + 1;	
	
}

else
{
		if (rd16== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 32768;
		}
		
		if (rd17== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 16384;
		}
		if (rd18== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 8192;
		}
		if (rd19== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 4096;
		}
		if (rd20== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 2048;
		}
		if (rd21== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 1024;
		}
		if (rd22== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 512;
		}
		if (rd23== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 256;
		}
		if (rd24=='0')
		{
			add = add + 0;
		}else
		{
			add = add + 128;
		}
		if (rd25=='0')
		{
			add = add + 0;
		}else
		{
			add = add + 64;
		}
		if (rd26== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 32;
		}
		if (rd27== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 16;
		}
		if (rd28== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 8;
		}
		if (rd29== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 4;
		}
		if (rd30== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 2;
		}
		if (rd31== '0')
		{
			add = add + 0;
		}else
		{
			add = add + 1;
		}

}
printf("\n%d", add);
return add;

}

///////////////////////////////jump/////////////////////////////////////


int jump(char jp6,char jp7,char jp8,char jp9,char jp10,char jp11,char jp12,char jp13,char jp14,char jp15,char jp16,char jp17,char jp18,char jp19,char jp20,char jp21,char jp22,char jp23,char jp24,char jp25,char jp26,char jp27,char jp28,char jp29,char jp30,char jp31)

{
	
FILE *you;
//you = fopen("test2.txt","a");	
 
 int add=0;
{

if (jp6== '0')
{
	add = add + 0;
	//	printf("%s","b1b");
	//	printf("\n%d",add);
}else
{
	add = add + 33554432;
	//	printf("%s","b2b");
	//	printf("\n%d",add);
}

if (jp7== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 16777216;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp8== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 8388608;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp9== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 4194304;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp10== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 2097152;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}

if (jp11== '0')
{
	add = add + 0;
	//	printf("%s","b1b");
	//	printf("\n%d",add);
}else
{
	add = add + 1048576;
	//	printf("%s","b2b");
	//	printf("\n%d",add);
}

if (jp12== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 524288;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp13== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 262144;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp14== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 131072;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp15== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 65536;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}


if (jp16== '0')
{
	add = add + 0;
	//	printf("%s","b1b");
	//	printf("\n%d",add);
}else
{
	add = add + 32768;
	//	printf("%s","b2b");
	//	printf("\n%d",add);
}

if (jp17== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 16384;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp18== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 8192;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp19== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 4096;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp20== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 2048;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp21== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 1024;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp22== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 512;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp23== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 256;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp24=='0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 128;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp25=='0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 64;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp26== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 32;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp27== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 16;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp28== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 8;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp29== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 4;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp30== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 2;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}
if (jp31== '0')
{
	add = add + 0;
	//	printf("%s","c1c");
	//	printf("\n%d",add);
}else
{
	add = add + 1;
	//	printf("%s","c2c");
	//	printf("\n%d",add);
}

}
printf("\n%d", add);

return add;
//fprintf(you,"%s","  #");
//fprintf(you,"%d", add);
		
	
}

#include<dir.h>
#include<dos.h>
#include<bios.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int count=0,count1=0;
char Nebuf[200]="",SNebuf[200]="",knodes[100][100];

int valid(char * dname) {
	int i, flag = 0;
	for (i = 0; dname[i] != '\0'; i++) {
		if (isalpha(dname[i]) != 0) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 1;
	}
	return 0;
}

int valid1(char * movID) {
	int i, flag = 0;
	for (i = 0; movID[i] != '\0'; i++) {
		if (isalpha(movID[i]) != 0 || isdigit(movID[i])!=0) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 1;
	}
	return 0;
}

int valid2(char * pt) {
	int i, flag = 0;
	for (i = 0; pt[i] != '\0'; i++) {
		if (isdigit(pt[i])!=0) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 1;
	}
	return 0;
}
int valid3(char * rt) {
	int i, flag = 0;
	for (i = 0; rt[i] != '\0'; i++) {
		if (isalpha(rt[i]!=0)||rt[i] == ','||rt[i] == '-') {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 1;
	}
	return 0;
}

class Movie;

class IOBUFFER
{
   public:
	   void initialize()
	{
	    Nextbyte=0;Buffersize=75;Buffer[0]=0;
	}

	virtual int Read(istream &,int)=0;
	virtual int Write(ostream &)=0;
	virtual int pack(Movie &,fstream &)=0;
	virtual int unpack(Movie &,fstream &)=0;

   protected:
	char Buffer[100];
	int Buffersize;
	int Nextbyte;
};

class FixedLengthBuffer:public IOBUFFER
{
public:
int Read(istream &,int);
int Write(ostream &);
};
class VariableFieldBuffer:public FixedLengthBuffer
{
    public:
	int pack(Movie &,fstream &);
	int unpack(Movie &,fstream &);
};
/*Student class*/

class Movie
{
public:
char mov_ID[60],mov_Name[60],language[60],actor[60],actress[60],director[60],duration[60],release_date[60],rating[60];
	Movie()
	 {
	   mov_ID[0]=0;
	   mov_Name[0]=0;
	   language[0]=0;
	   actor[0]=0;
	   actress[0]=0;
	   director[0]=0;
	   duration[0]=0;
	   release_date[0]=0;
	   rating[0]=0;
	 }
    void Input();
    void Modify();
    void Assign1(Movie &);
    void Display();
    int  Binary(char *);
    void Index();
    void del();
    void KeySort();
    void Indexdisplay(int);
    void Invertprimary();
    void Invertsecondary();
    void Invertsecondarysort();
    void CheckDup();
    void InvertSecondarySort();
    int  InvertSecondSearch(char *);
};

class fsearch
{
 public:
 int Search(char *);
};

int Movie::Binary(char *key)
{
 int mid=0,k,ptr1,low,high,i=0;
 low=0;
 high=count-1;
 char dname[60]="",recaddr[10],*endptr;
 int l=strlen(key);
    while(1)
	  {         for(int j=0;j<15;j++)
			dname[j]='\0';
		mid=(low+high)/2;

		if(low>high)
			return -1;

		for(i=0;knodes[mid][i]!='|';i++)
			dname[i]=knodes[mid][i];
		i++;

		for(int n=0;knodes[mid][i]!='|';i++)
			recaddr[n++]=knodes[mid][i];

		int num=strtol(recaddr,&endptr,10);
		ptr1 = strnicmp(dname,key,l);

		if (ptr1 > 0)
		      high=mid-1;
		else if (ptr1 < 0)
			   low=mid+1;
		else if(ptr1==0)
		return num;

	}
}
Movie s1,s2;

void Movie::Modify()
{
	char key[60],Buff[200];
	int size=0,found=0,asize=75,Next=0;
	clrscr();
	cout<<"\n\tEnter the movie id to search: ";
	cin>>key;
	VariableFieldBuffer b;
	fstream file("list1.txt",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	while(b.unpack(*this,file))
	  {
		if(strcmpi(mov_ID,key)==0)
		{
			found=1;
			break;
		}
	     size=size+75;
	  }
	if(found==1)
	 {
		char choice[10];
		cout<<"\n\n\t\t\t\tRecord is found ...."<<endl<<endl;
		cout<<"\n\t\t\tDetails Of Record";

		cout<<"\n\t\t\tMovie ID:"<<mov_ID<<endl;
		cout<<"\n\t\t\tMovie name:"<<mov_Name<<endl;
		cout<<"\n\t\t\tLanguage:"<<language<<endl;
		cout<<"\n\t\t\tActor:"<<actor<<endl;
		cout<<"\n\t\t\tActress:"<<actress<<endl;
		cout<<"\n\t\t\tDirector :"<<director<<endl;
		cout<<"\n\t\t\tDuration:"<<duration<<endl;
		cout<<"\n\t\t\tRelease Date:"<<release_date<<endl;
		cout<<"\n\t\t\tRating:"<<rating<<endl;
		cout<<"\n\n\t\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\n\n";
		cout<<"\nDo You Want To Update MOVIE ID(Y/N):";
		cin>>choice;
		if(choice[0]=='y'||choice[0]=='Y')
		{
			cout<<"\n\t\tEnter the Movie ID:";
			cin>>mov_ID;
		}
		cout<<"\nDO You Want To Update movie name(Y/N):";
		cin>>choice;
		if(choice[0]=='y'||choice[0]=='Y')
		{
			cout<<"\n\t\tEnter the movie name  :";
			cin>>mov_Name;
		}

		cout<<"\nDO You Want To Update Language(Y/N):";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the language:";
		  cin>>language;
		}

		cout<<"\nDO You Want To Update Actor(Y/N)  :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the Actor:";
		  cin>>actor;
		}

		cout<<"\nDO You Want To Update Actress(Y/N)  :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the actress:";
		  cin>>actress;
		}

		cout<<"\nDO You Want To Update Director(Y/N)    :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the director:";
		  cin>>director;
		}
		cout<<"\nDO You Want To Update duration(Y/N)    :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the duration:";
		  cin>>duration;
		}

		cout<<"\nDO You Want To Update release date(Y/N)    :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the release date:";
		  cin>>release_date;
		}

		cout<<"\nDO You Want To Update rating(Y/N)    :";
		cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tEnter the rating       :";
		  cin>>rating;
		}
		

		for(int i=0;i<75;i++)
		{
		  Buff[i]=' ';
		}

	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.mov_ID); strcat(Buff,"|");
	       strcat(Buff,s1.mov_Name);strcat(Buff,"|");
	       strcat(Buff,s1.language);strcat(Buff,"|");
	       strcat(Buff,s1.actor);strcat(Buff,"|");
	       strcat(Buff,s1.actress);strcat(Buff,"|");
	       strcat(Buff,s1.director);strcat(Buff,"|");
	       strcat(Buff,s1.duration);strcat(Buff,"|");
	       strcat(Buff,s1.release_date);strcat(Buff,"|");
	       strcat(Buff,s1.rating);strcat(Buff,"|");
	       Next=strlen(Buff);

	       if(Next>asize)
		  cout<<"\n\n\t\t\tRecord Overflow .... \n";
	       else
		 {
		   file.seekp(size);
		   file.write(Buff,asize);
		   cout<<"\n\n\t\t\t\tRecord Is Updated ....\n";
		 }

	 }

    else
		cout<<setw(40)<<"\n\n\n\t\t\tRecord Not Found ....\n";

     file.close();
     getch();
}

void Movie::Assign1(Movie &s1)
{
	strcpy(s1.mov_ID,mov_ID);
	strcpy(s1.mov_Name,mov_Name);
	strcpy(s1.language,language);
	strcpy(s1.actor,actor);
	strcpy(s1.actress,actress);
	strcpy(s1.director,director);
	strcpy(s1.duration,duration);
	strcpy(s1.release_date,release_date);
	strcpy(s1.rating,rating);
}
void Movie::Input()
{
	int k,value,flag;
	Movie a;
	fsearch v;
	VariableFieldBuffer b;
	fstream file;
	clrscr();

	cout<<"\n\tEner the movie id :";
	cin>>mov_ID;
	   flag = valid1(mov_ID);
		if (!flag) {
			Input();
	}

	while(v.Search(mov_ID)==1)
	 {
		cout<<"\n\nDuplicate Entry Re-Enter The Movie ID Value: ";
		cin>>mov_ID;
	 }
	 cout<<"\n\tEnter the movie name    :";
	 cin>>mov_Name;
	 flag = valid( mov_Name);
		if (!flag) {
	cout << "Movie Name accept only characters" << endl;
	 cout<<"\n\tEnter the movie name    :";
		 cin>>mov_Name;

	}
	 cout<<"\n\tEnter the Language :";
	 cin>>language;
	 flag = valid( language);
			if (!flag) {
			cout << "Language accept only characters" << endl;
	 cout<<"\n\tEnter the language :";
	 cin>>language;

	}
	 cout<<"\n\tEnter the actor:";
	 cin>>actor;
	 flag = valid3(actor);
		if (!flag) {
			cout << "Actor accept only characters and - symbol" << endl;
			cout<<"\n\tEnter the actor:";
				 cin>>actor;

		}
	 cout<<"\n\tEnter the Actress  :";
	 cin>>actress;
	 flag = valid3(actress);
		if (!flag) {
			cout << "Stop accept only characters and - symbol" << endl;
			cout<<"\n\tEnter the actress  :";
				 cin>>actress;

		}
	 cout<<"\n\tEnter the director    :";
	 cin>>director;
	 cout<<"\n\tEnter the duration :";
	 cin>>duration;
	  flag = valid2(duration);
		if (!flag) {
		 cout<<"\n\tEnter duration  :";
	 cin>>duration;

	}
	 cout<<"\n\tEnter the release date:";
	 cin>>release_date;
	 cout<<"\n\tEnter the rating :";
	 cin>>rating;
	 

	 file.open("list1.txt",ios::app);
	 k=b.pack(*this,file);
	 file.close();
	 if(k==1)
	 cout<<"\n\n\t\t\tRecord Inserted ....\n\n";
	else
	 cout<<"some problem";
}

/*Display function*/

void Movie :: Display()
{
	VariableFieldBuffer c;
	fstream file("list1.txt",ios::in);
	file.seekg(0,ios::beg);
	while(c.unpack(*this,file))
	 {
	   clrscr();
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAY OF RECORDS"<<endl<<endl;
	 //  for(int i=0;i<80;i++)   cout<<'*';   cout<<endl;
	   cout<<setw(20)<<" "<<"Movie Id    :  "<<mov_ID<<endl<<endl;
	   cout<<setw(20)<<" "<<"Movie NAME:  "<<mov_Name<<endl<<endl;
	   cout<<setw(20)<<" "<<"Language:  "<<language<<endl<<endl;
	   cout<<setw(20)<<" "<<"Actor    :  "<<actor<<endl<<endl;
	   cout<<setw(20)<<" "<<"Actress    :  "<<actress<<endl<<endl;
	   cout<<setw(20)<<" "<<"Director      :  "<<director<<endl<<endl;
	   cout<<setw(20)<<" "<<"Duration:  "<<duration<<endl<<endl;
	   cout<<setw(20)<<" "<<"Release Date  :  "<<release_date<<endl<<endl;
	   cout<<setw(20)<<" "<<"Rating   :  "<<rating<<endl<<endl;

	 //  for(i=0;i<80;i++) cout<<'*';
	   cout<<endl<<endl<<setw(39)<<" ";
	   getch();
	 }
      if(!(c.unpack(*this,file)))
       {
	 cout<<endl<<endl<<endl<<endl<<setw(40)<<"NO RECORDS FOUND ....";
	 getch();
	 return;
	   }

    file.clear();
    file.close();
}

/*Delete function*/

void Movie::del()
{
char key[60],Buff[200];
	int size=0,asize=75,found=0;
	clrscr();
	cout<<"\nENTER THE MOVIE ID  TO BE DELETED  :";
	cin>>key;
	fsearch u;
	found=u.Search(key);
	if(found==1)
	cout<<"\n\n\n\t\t\tRecord Is Found ....";
	else
	{
	cout<<"\n\n\n\t\t\tRecord Is Not Found ....";
	return;
	 }
	VariableFieldBuffer b;
	fstream file,file1;
	if(found==1)
	{
	file.open("list1.txt",ios::app|ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	file1.open("b1.txt",ios::out);
	file1.seekg(0,ios::beg);
	 while(b.unpack(*this,file))
	 {
	    if(strcmp(mov_ID,key)==0)
	      {
	      cout<<"\n\n\n\n\t\tRecord Is Deleted ....\n";
			found=1;
	      }
	      else
	      {
	       for(int i=0;i<75;i++)
	       {
		  Buff[i]=' ';
	       }
	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.mov_ID); strcat(Buff,"|");
	       strcat(Buff,s1.mov_Name);strcat(Buff,"|");
	       strcat(Buff,s1.language);strcat(Buff,"|");
	       strcat(Buff,s1.actor);strcat(Buff,"|");
	       strcat(Buff,s1.actress);strcat(Buff,"|");
	       strcat(Buff,s1.director);strcat(Buff,"|");
	       strcat(Buff,s1.duration);strcat(Buff,"|");
	       strcat(Buff,s1.release_date);strcat(Buff,"|");
	       strcat(Buff,s1.rating);strcat(Buff,"|");

	       file1.write(Buff,asize);
	       size=size+75;
	      }
	  }
	}
	file1.close();
	 file.close();
	  unlink("list1.txt");
	  rename("b1.txt","list1.txt");

	 getch();
}

void Movie::KeySort()
{
char Buffer[15],str1[15]="",str2[15]="";
int length=15,ptr,i=0;
fstream file("index1.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;
		for(int j=0;j<15;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(int j=0;j<15;j++)
knodes[i][j]=Buffer[j];
file.close();

for(i=0;i<count;i++)
{
	for(int m=0;m<15;m++)
	str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<15;m++)
	str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);
	while(j>=0&&ptr<0)
	{
	     for(m=0;m<15;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<15;m++)
	knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void  Movie::Index()
{
	int size=0,length=75;
	char buid[60]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list1.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			 break;
			 for(int i=0;IBuff[i]!='|';i++)
			 buid[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<buid<<"|"<<count<<"|";
			 size=size+15;
		  }
	 nfile.close();
	 ofile.close();
}
void Movie :: Indexdisplay(int size)
{
	VariableFieldBuffer c;
	fstream file("list1.txt",ios::in);
	file.seekg(size,ios::beg);
	c.unpack(*this,file);
	   clrscr();
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING OF RECORD'S"<<endl;

	   cout<<setw(20)<<" "<<"Movie Id    :  "<<mov_ID<<endl<<endl;
	   cout<<setw(20)<<" "<<"Movie NAME:  "<<mov_Name<<endl<<endl;
	   cout<<setw(20)<<" "<<"Langauge:  "<<language<<endl<<endl;
	   cout<<setw(20)<<" "<<"Actor    :  "<<actor<<endl<<endl;
	   cout<<setw(20)<<" "<<"Actress     :  "<<actress<<endl<<endl;
	   cout<<setw(20)<<" "<<"Director     :  "<<director<<endl<<endl;
	   cout<<setw(20)<<" "<<"Duration:  "<<duration<<endl<<endl;
	   cout<<setw(20)<<" "<<"Release Date :  "<<release_date<<endl<<endl;
	   cout<<setw(20)<<" "<<"Rating   :  "<<rating<<endl<<endl;
	   cout<<endl<<endl<<setw(39)<<" ";
	   getch();
    file.clear();
    file.close();
}

void Movie::Invertprimary()
{
int size=0,length=75;
	char buss[60]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list1.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index11.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			  break;
			 for(int i=0;IBuff[i]!='|';i++)
			 buss[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<count<<"|"<<buss<<"|"<<-1<<"|";
			 size=size+25;
		  }

	 nfile.close();
	 ofile.close();
}

void Movie::Invertsecondary()
{
int size=0,length=75;
	char buss[60]="0",IBuff[75]="",name[60]="";
      count=0;
      Movie as;
	ifstream ofile("list1.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("second11.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
				  break;

			 for(int i=0;IBuff[i]!='|';i++)
				 buss[i]=IBuff[i];
			 i++;

			 for(int k=0;IBuff[i]!='|';i++)
				name[k++]=IBuff[i];
			 name[k]='\0';
			 count++;
			 nfile.seekp(size);
			 nfile<<name<<"|"<<count<<"|";
			 size=size+25;
		  }
	 nfile.close();
	 ofile.close();
}

void Movie::Invertsecondarysort()
{
char Buffer[25],str1[30]="",str2[30]="";
int length=25,ptr,i=0;
fstream file("second11.txt",ios::in);
file.seekg(0,ios::beg);
for(int j=0;j<25;j++)
knodes[i][j]='\0';
while(1)
{
	for(int j=0;j<25;j++)
		Buffer[j]='\0';
	file.read(Buffer,length);

	if(file.fail())
		break;

	for( j=0;j<25;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for( j=0;j<25;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{      j=0;
	for(int m=0;m<25;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<25;m++)
		str2[m]=knodes[j][m];
		ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<25;m++)
		    knodes[j+1][m]=knodes[j][m];
	     j--;
	goto a;
	}

	for(m=0;m<25;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void Movie::CheckDup()
{
	  int found,size=0,length=75;
	  char nname[60]="",kname[60]="",klen[5]="",*endptr,Buffer[75]="",bd[15]="";
	  Movie sss;
	  fstream qfile("second31.txt",ios::out);
	  qfile.seekp(0,ios::beg);
	  fstream ffile("second21.txt",ios::out);
	  ffile.seekp(0,ios::beg);
	  fstream file("second11.txt",ios::in|ios::out);
	  file.seekg(0,ios::beg);
	   found=count;
	  int i=0;
	  while(i<count)
	  {
	  int l=0;
		 for(int m=0;m<20;m++)
			 kname[m]='\0';
		 for(int j=0;knodes[i][j]!='|';j++)
			 kname[j]=knodes[i][j];
		 j++;

		for(int n=0;knodes[i][j]!='|';j++)
			 klen[n++]=knodes[i][j];


		int p=strlen(kname);
		int  ptr=strnicmp(kname,nname,p);

		if(ptr==0)
		{
		ffile<<klen<<"|";
			fstream nfile("list1.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);
			nfile.read(Buffer,length);
			 for(int i=0;Buffer[i] != '|';i++)
				bd[l++]=Buffer[i];
			 bd[l]='\0';
			 qfile<<bd<<"|";

		found=found+1;
		nfile.close();
		}

	       if(ptr>0)
		 {
			ffile.seekp(size);
			strcpy(nname,kname);
			ffile<<kname<<"|"<<klen<<"|";
			fstream nfile("list1.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);

			nfile.read(Buffer,length);

			for(int i=0;Buffer[i] != '|';i++)
				bd[l++]=Buffer[i];

			bd[l]='\0';
			qfile.seekp(size);
			qfile<<kname<<"|"<<bd<<"|";
			nfile.close();
			size=size+30;
		 }

		i++;
	     found--;
	}
  ffile.close();
  file.close();
}

void Movie::InvertSecondarySort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0;
fstream file("second31.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
		break;

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	file.close();

for(i=0;i<count;i++)
{     j=0;
	for(int m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
		     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];

for(i=0;i<count;i++)
	 for(j=0;j<30;j++)
		cout<<knodes[i][j];
}

int  Movie::InvertSecondSearch(char *key)
{
clrscr();
char str1[30]="";
int found=0;
char Buffer[200];
int length=30,ptr,i=0;
fstream file("second31.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
	break;
	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for(int j=0;j<30;j++)
knodes[i][j]=Buffer[j];

for( i=0;i<count;i++)
{
 for(int j=0;knodes[i][j]!='|';j++)
     str1[j]=knodes[i][j];
     str1[j]='\0';
     int l=strlen(key);
     int ptr=strnicmp(str1,key,l);
     if(ptr==0)
     {
	found=1;
	break;
	 }
 }

if(found==1)

{
	for(int j=0;j<30;j++)
		cout<<knodes[i][j];
return 1;
}
	else
		return -1;
}

int FixedLengthBuffer::Read(istream &stream,int size)
{
stream.read(Buffer,Buffersize+size);
return stream.good();
}

int FixedLengthBuffer::Write(ostream &stream)
{
stream.write(Buffer,Buffersize);
return stream.good();
}

/*Pack Function*/
void normal();
void screen();
void screen1();

int VariableFieldBuffer::pack(Movie &s,fstream &file)
{
	int value;
	initialize();

	for(int i=0;i<75;i++)
	{
	   Buffer[i]=' ';
	}

	memcpy(&Buffer[0],&Buffersize,sizeof(Buffersize));
	strcpy(Buffer,s.mov_ID); strcat(Buffer,"|");
	strcat(Buffer,s.mov_Name);strcat(Buffer,"|");
	strcat(Buffer,s.language);strcat(Buffer,"|");
	strcat(Buffer,s.actor);strcat(Buffer,"|");
	strcat(Buffer,s.actress);strcat(Buffer,"|");
	strcat(Buffer,s.director);strcat(Buffer,"|");
	strcat(Buffer,s.duration);strcat(Buffer,"|");
	strcat(Buffer,s.release_date);strcat(Buffer,"|");
	strcat(Buffer,s.rating);strcat(Buffer,"|");

	Nextbyte=strlen(Buffer);

	if(Nextbyte>Buffersize)
	  return 0;

	else
	  value=Write(file);
	  return value;
}

/*Unpack Function*/

int VariableFieldBuffer::unpack(Movie &s,fstream &file)
{
	initialize();
	Nextbyte=0;
	int value = Read(file,Nextbyte);
	if(value==0) return 0;
	if(Buffersize > 0)
	{
	int j=0;
	      for(int i=0;Buffer[i] != '|';i++)
	       s.mov_ID[j++]=Buffer[i];
	       s.mov_ID[j]='\0';
	       i++;

	      for(j=0;Buffer[i]!='|' ;i++)
	       s.mov_Name[j++]=Buffer[i];
	       s.mov_Name[j]='\0';
		   i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.language[j++]=Buffer[i];
		s.language[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.actor[j++]=Buffer[i];
		s.actor[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		 s.actress[j++]=Buffer[i];
		 s.actress[j]='\0';
		 i++;
	       for(j=0;Buffer[i]!= '|';i++)
		s.director[j++]=Buffer[i];
		s.director[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.duration[j++]=Buffer[i];
		s.duration[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		 s.release_date[j++]=Buffer[i];
		 s.release_date[j]='\0';
		 i++;
	      for(j=0;Buffer[i]!= '|';i++)
		s.rating[j++]=Buffer[i];
		s.rating[j]='\0';
		i++;

	       Nextbyte=Buffersize+75;
	       return 1;
	}
return 0;
}

/*Function to search a key*/

int fsearch::Search(char *key)
{
	  int found=0;
	  Movie s1;
	  VariableFieldBuffer b;
	  fstream file("list1.txt",ios::in||ios::out);
	  file.seekg(0,ios::beg);
	  while(b.unpack(s1,file))
		 if(strcmpi(s1.mov_ID,key)==0)
		  found=1;
		 file.close();
	  return found;
}

/*Douoblebox design*/

void drawdoublelinebox(int x,int y,int len,int bdt)
{
	gotoxy(x,y);
	cprintf("*");
		gotoxy(x,y+bdt);
	cprintf("*");
	gotoxy(x+len,y);
	cprintf("*");
	gotoxy(x+len,y+bdt);
	cprintf("*");
	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("*");
		gotoxy(i,y+bdt);
		cprintf("*");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("*");
		gotoxy(x+len,j);
		cprintf("*");
			}
}

/*Double box design*/

void drawsinglelinebox(int x,int y,int len,int bdt)
{                                            // (x,y) : co.ord. of 1st tip
	gotoxy(x,y);                         // len : length of box
	cprintf("*");                        // bdt : breadth of box
	gotoxy(x,y+bdt);
	cprintf("*");
	gotoxy(x+len,y);
	cprintf("*");
	gotoxy(x+len,y+bdt);
	cprintf("*");

	for(int i=x+1;i<x+len;i++)
	{
		gotoxy(i,y);
		cprintf("*");
		gotoxy(i,y+bdt);
		cprintf("*");
	}
	for(int j=y+1;j<y+bdt;j++)
	{
		gotoxy(x,j);
		cprintf("*");
		gotoxy(x+len,j);
		cprintf("*");
	}
}

/*Main function*/

void main()
{
int choice,ch,cho,a;
char key[60];
Movie s;

clrscr();
do
{
     screen();

     cout<<"      ENTER YOUR CHOICE  :   ";
     cin>>ch;
	  switch(ch)
	  {
	     case 1:do
	      {
	      clrscr();
	      drawdoublelinebox(17,7,44,14);
	     // textcolor(8);
	      textbackground(BLACK);
		  clrscr();
		  textbackground(BLACK);
	      gotoxy(25,3);
	      textcolor(RED);
	      cprintf("        MOVIE  RECORDS       ");
	      gotoxy(25,4);
	  //    cprintf(" ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ ");
	      int z=19,q=10;
	      textcolor(RED);
	      drawdoublelinebox(17,7,44,14);
	      gotoxy(28,7);
	      textbackground(BLACK);
	      textcolor(RED);
	      cprintf("        M E N U       " );
	      normal();
	      textcolor(WHITE);
	      gotoxy(z,q++);
	      cout<<"1. ADD MOVIE DETAILS";
	      gotoxy(z,q++);
	      cout<<"2. UPDATE MOVIE DETAILS";
		  gotoxy(z,q++);
		  cout<<"3.SHOW MOVIE DETAILS";
	      gotoxy(z,q++);

	      cout<<"4. REMOVE MOVIE DETAILS";
	      gotoxy(z,q++);
	      cout<<"5. EXIT";
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      gotoxy(z,q++);
	      cout<<"      ENTER YOUR CHOICE   : ";
	      cin>>choice;

		 switch(choice)
		 {
		  case 1:s.Input();
			 break;

		  case 2:s.Modify();
			 break;

		  case 3:s.Display();
			 break;

		  case 4:s.del();
			 break;

		  case 5:clrscr();
			 screen();
			 break;

		  default:sound(600);delay(500);nosound();break;
		}
	}while(choice!=5);break;

case 2 :

     do
     {
      screen1();
      cout<<"      ENTER YOUR CHOICE   : ";
      cin>>cho;

	switch(cho)
	{
	cd:
	s.Index();
	s.KeySort();
	gotoxy(20,15);
       drawdoublelinebox(17,7,44,14);
	gotoxy(18,10);
	cprintf("Enter the Primary key(MOVIE id):\n ");
	gotoxy(18,13);
	cin>>key;
	a=s.Binary(key);
	if(a==-1)
	{gotoxy(25,40);
	cout<<"Record not found....!";}
	else
	{
		a=a-1;
		a=a*75;
		s.Indexdisplay(a);
		cout<<"\n\n\nSuccessfull search......  :";
	}getch();
	break;

case 1: s.Invertprimary();
	s.Invertsecondary();
	s.Invertsecondarysort();
	s.CheckDup();
	clrscr();
	drawdoublelinebox(17,7,44,14);
	gotoxy(18,10);
	cout<<"Enter the Secondary key(movie name):\n ";
	gotoxy(18,13);
	cin>>key;
	a=s.Binary(key);
	if(a==-1)
	{gotoxy(25,40);
	cout<<"Record not found....!";
	}
	s.InvertSecondarySort();
	int b=s.InvertSecondSearch(key);
	if(b==1)
	goto cd;
else
{
	clrscr();
	gotoxy(20,25);
	cout<<"Record not found...!";
}
break;

case 2:clrscr();
}
}

while(cho!=2);screen();break;

case 3:exit(0);

default: sound(100);delay(500);nosound();break;
}
}while(ch!=3);
}

void screen()
{
 int g=19,h=10;

     textbackground(BLACK);
     gotoxy(25,3);
     textcolor(RED);
     cprintf("     MOVIE INFORMATION SYSTEM       ");
     gotoxy(25,4);
    // cprintf(" ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ ");
     drawdoublelinebox(17,7,44,14);
     gotoxy(28,7);
     textbackground(BLACK);
	 textcolor(RED);
	 cprintf("          MENU          " );
     normal();
     textcolor(WHITE);
     gotoxy(g,h++);
     cout<<"   1.MOVIE RECORD";
     gotoxy(g,h++);
     cout<<"   2. INDEXING";
     gotoxy(g,h++);
     cout<<"   3. EXIT";
     gotoxy(g,h++);
     gotoxy(g,h++);
     gotoxy(g,h++);
     normal();
}

void normal()  // to obtain normal background
{
	textattr(WHITE); // textattr sets text attributes for text-window functions
	textcolor(WHITE);// textcolor selects a new character color in text mode
	textbackground(BLACK);//textbackground selects a new text background color
	_setcursortype(_NORMALCURSOR); /* sets cursor type to normal underscore
						 type cursor  */
}

void screen1()
{
     int b,g=19,h=10;
     clrscr();
     textbackground(BLACK);
     gotoxy(25,3);
     textcolor(RED);
     cprintf("        INDEXING      ");
     gotoxy(25,4);
  //   cprintf(" ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ ");
	 drawdoublelinebox(17,7,44,14);
	 gotoxy(28,7);
	 textbackground(BLACK);
	 textcolor(RED);
	 cprintf("       MAIN MENU      " );
	 normal();
	 textcolor(WHITE);
	 gotoxy(g,h++);
	 cout<<"1. INVERTED LIST";
	 gotoxy(g,h++);
	 cout<<"2. EXIT";
	 gotoxy(g,h++);
	 gotoxy(g,h++);
	 gotoxy(g,h++);
}



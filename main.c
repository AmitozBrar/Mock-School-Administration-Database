#include <stdio.h>
#include <string.h>
#include <sqlite3.h> 

static int callback(void* data, int argc, char** argv, char** ColName){
   
   for(int i = 0; i<argc; i++){
      printf("%s = %s\n", ColName[i], argv[i]);
   }
   
   return 0;
}


int main(int argc, char* argv[]) {
   sqlite3* db;
   int c;
   
   

   c = sqlite3_open_v2("SchoolSystem.db", &db, SQLITE_OPEN_READWRITE, NULL);

   if(c) {
      printf("Can't open database! %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      printf("Connect to database successfully.\n");
   }
   
   char* errMsg = 0; 
   //create SQL statement
   char* sql = "CREATE TABLE Student( \
	Id INTEGER PRIMARY KEY AUTOINCREMENT, \
	Name VARCHAR(255) NOT NULL, \
	Email VARCHAR(255) NOT NULL, \
	Year INT NOT NULL, \
	VolHours VARCHAR(255) NOT NULL, \
	Gender VARCHAR(255) NOT NULL, \
	CONSTRAINT StudentPk UNIQUE(Id,Email)\
);";

   //execute SQL statement
   int r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      
   if( r != SQLITE_OK ){
       printf("SQL error: %s\n", errMsg);
       sqlite3_free(errMsg);
   } 
   else {
       printf("Table created successfully\n");
   }
   
	int choice =0;
	while(choice !=1){
	printf("--------------------------\nWelcome to the Blah Blah Blah School Administration portal\n");
	printf("1) exit\n");
	printf("2) list of students\n");
	printf("3) list of teachers\n");
	printf("4) list of clubs\n");
	printf("5) list of current classes\n");
	printf("6) list of past classes\n");
	printf("7) add a new student\n");
	printf("8) add a new teacher\n");
	printf("9) add a new club\n");
	printf("10) add a new class\n");
	printf("11) move a class to the past\n");
	printf("12) edit student\n");
	printf("13) edit Teacher\n");
	printf("14) edit club\n");
	printf("15) edit behaviour of a student\n");
	printf("16) delete student\n");
	printf("17) delete Teacher\n");
	printf("18) delete club\n");
	printf("19) delete behaviour of a student\n");
	
	
	
	
	printf("\n\n");
	printf("enter your choice: ");
	scanf("%d",&choice);
		
		if(choice == 1){
			
		}
		else if(choice ==2){//student list
			sql = "SELECT * from Student";

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, callback, 0, &errMsg);
   
   			if( r != SQLITE_OK ){
      				 printf("SQL  error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   				} 
   			else {
       			printf("Students are retrieved successfully\n");
   			}
			
			
			
		}
		else if(choice ==3){ //teacher list
						sql = "SELECT * from Teacher";

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, callback, 0, &errMsg);
   
   			if( r != SQLITE_OK ){
      				 printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   				} 
   			else {
       			printf("Teacher is retrieved successfully\n");
   			}
		
		}
		else if(choice ==4){// list of clubs
			sql = "SELECT * from Extracurriculars";

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, callback, 0, &errMsg);
   
   			if( r != SQLITE_OK ){
      				 printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   				} 
   			else {
       			printf("clubs are retrieved successfully\n");
   			}
		
		}
		else if(choice ==5){//list of current classes
			sql = "SELECT * from CurrentClasses";

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, callback, 0, &errMsg);
   
   			if( r != SQLITE_OK ){
      				 printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   				} 
   			else {
       			printf("current clases are retrieved successfully\n");
   			}
		
		}
		else if(choice ==6){// list of past classes
			sql = "SELECT * from PastClasses";

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, callback, 0, &errMsg);
   
   			if( r != SQLITE_OK ){
      				 printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   				} 
   			else {
       			printf("past classes are retrieved successfully\n");
   			}
		}
		else if(choice ==7){//add a new student
			char SId[10] ;
			char SFirstName[30] ;
			char SLastName[30];
			char SEmail[30];
			char SYear[2];
			char SVolHours[5];
			char SGender[10];
			
		
			printf("\n\nenter the id: ");
			scanf("%s", SId);
			
			printf("enter the first name: ");
			scanf("%s", SFirstName);
			
			printf("enter the last name: ");
			scanf("%s", SLastName);
			printf("enter the email: ");
			scanf("%s", SEmail);
			
			printf("enter Student Year: ");
			scanf("%s", SYear);
			printf("enter the Volunteer Hours: ");
			scanf("%s", SVolHours);
			
			printf("enter Gender: ");
			scanf("%s", SGender);
			
			//printf("%s",SGender);
			
			
			
			
			char command[100] = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
			 
			 strcat(command,SId);
			 strcat(command," ,'");
			 strcat(command,SFirstName);
			 strcat(command," ");
			 strcat(command,SLastName);
			 strcat(command,"' ,'");
			 strcat(command,SEmail);
			 strcat(command,"' ,");
			 strcat(command,SYear);
			 strcat(command," ,'");
			 strcat(command,SVolHours);
			 strcat(command," ','");
			 strcat(command,SGender);
			 strcat(command,"');");
			 printf("%s\n",command);
			 
			 sql = command;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("student inserted successfully\n");
   			}
			
			//new student also makes new behaviour corresponding to student number. (rework with constraints)
		
		}
		else if(choice ==8){// add a new teacher
			char TId[10] ;
			char TFirstName[30] ;
			char TLastName[30];
			char TDegree[30];
			char TYearsTaught[2];
			
		
			printf("\n\nenter the id: ");
			scanf("%s", TId);
			
			printf("enter the first name: ");
			scanf("%s", TFirstName);
			
			printf("enter the last name: ");
			scanf("%s", TLastName);
			
			printf("enter degree: ");
			scanf("%s", TDegree);
			
			printf("enter Years Taught: ");
			scanf("%s", TYearsTaught);
			
			//printf("%s",SGender);
			
			
			
			
			char Tcommand[100] = "INSERT INTO Teacher(Id, Name, Degree, YearsTaught) VALUES( ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
			 
			 strcat(Tcommand,TId);
			 strcat(Tcommand," ,'");
			 strcat(Tcommand,TFirstName);
			 strcat(Tcommand," ");
			 strcat(Tcommand,TLastName);
			 strcat(Tcommand,"' ,'");
			 strcat(Tcommand,TDegree);
			 strcat(Tcommand,"' ,");
			 strcat(Tcommand,TYearsTaught);
			 strcat(Tcommand," );");
			 printf("%s\n",Tcommand);
			 
			 sql = Tcommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("student inserted successfully\n");
   			}
		}
		else if(choice ==9){// add a new club
			char CId[10] ;
			char CSport[30] ;
			char CCompetitive[30];
			char CLeisure[30];
			char CLeader[2];
			
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			printf("enter the Sport: ");
			scanf("%s", CSport);
			
			printf("enter the Competitive: ");
			scanf("%s", CCompetitive);
			
			printf("enter the Leisure: ");
			scanf("%s", CLeisure);
			
			printf("enter Leader Id: ");
			scanf("%s", CLeader);
			
			//printf("%s",SGender);
			
			
			
			
			char Ccommand[100] = "INSERT INTO Extracurriculars(Id, Sports, Competitve, Leisure, StudentId) VALUES( ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
			 
			 strcat(Ccommand,CId);
			 strcat(Ccommand," ,'");
			 strcat(Ccommand,CSport);
			 strcat(Ccommand,"' ,'");
			 strcat(Ccommand,CCompetitive);
			 strcat(Ccommand,"' ,'");
			 strcat(Ccommand,CLeisure);
			 strcat(Ccommand,"' ,");
			 strcat(Ccommand,CLeader);
			 strcat(Ccommand,");");
			 printf("%s\n",Ccommand);
			 
			 sql = Ccommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("student inserted successfully\n");
   			}
		}
		else if(choice ==10){//add a new class
			char CId[10] ;
			char CName[30] ;
			char CGrades[30];
			char CTeacherId[30];
			char CStudentId[2];
			
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			printf("enter the Name: ");
			scanf("%s", CName);
			
			printf("enter the Grades: ");
			scanf("%s", CGrades);
			
			printf("enter the TeacherId: ");
			scanf("%s", CTeacherId);
			
			printf("enter student Id: ");
			scanf("%s", CStudentId);
			
			//printf("%s",SGender);
			
			
			
			
			char Ccommand[100] = "INSERT INTO CurrentClasses(Id, Name, Grades, TeacherId, StudentId) VALUES( ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
			 
			 strcat(Ccommand,CId);
			 strcat(Ccommand," ,'");
			 strcat(Ccommand,CName);
			 strcat(Ccommand,"' ,'");
			 strcat(Ccommand,CGrades);
			 strcat(Ccommand,"' ,");
			 strcat(Ccommand,CTeacherId);
			 strcat(Ccommand," ,");
			 strcat(Ccommand,CStudentId);
			 strcat(Ccommand,");");
			 printf("%s\n",Ccommand);
			 
			 sql = Ccommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("CurrentClass inserted successfully\n");
   			}
		}
		else if(choice ==11){// move class to the past
		
		}
		else if(choice ==12){// edit student
			char SId[10] ;
			char SFirstName[30] ;
			char SLastName[30];
			char SEmail[30];
			char SYear[2];
			char SVolHours[5];
			char SGender[10];
			
		
			printf("\n\nenter the id of student you want to change: ");
			scanf("%s", SId);
			
			printf("enter the first name: ");
			scanf("%s", SFirstName);
			
			printf("enter the last name: ");
			scanf("%s", SLastName);
			printf("enter the email: ");
			scanf("%s", SEmail);
			
			printf("enter Student Year: ");
			scanf("%s", SYear);
			printf("enter the Volunteer Hours: ");
			scanf("%s", SVolHours);
			
			printf("enter Gender: ");
			scanf("%s", SGender);
			
			//printf("%s",SGender);
			
			
			
			
			
			char command[100] = "UPDATE Student SET  ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
		
			 
			 strcat(command," Name = '");
			 strcat(command,SFirstName);
			 strcat(command," ");
			 strcat(command,SLastName);
			 strcat(command,"', Email = '");
			 strcat(command,SEmail);
			 strcat(command,"' , Year = ");
			 strcat(command,SYear);
			 strcat(command," , VolHours = '");
			 strcat(command,SVolHours);
			 strcat(command,"' , Gender ='");
			 strcat(command,SGender);
			
			 strcat(command," ' WHERE Id = ");
			 strcat(command,SId);
			 strcat(command,";");
			 printf("%s\n",command);
			 sql = command;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("student inserted successfully\n");
   			}
			
			
		
			
		
		}
		else if(choice ==13){//find teacher
		
			char TId[10] ;
			char TFirstName[30] ;
			char TLastName[30];
			char TDegree[30];
			char TYearsTaught[2];
			
			printf("\n\nenter the id: ");
			scanf("%s", TId);
			
			printf("enter the first name: ");
			scanf("%s", TFirstName);
			
			printf("enter the last name: ");
			scanf("%s", TLastName);
			
			printf("enter degree: ");
			scanf("%s", TDegree);
			
			printf("enter Years Taught: ");
			scanf("%s", TYearsTaught);
			
			
			char command[100] = "UPDATE Teacher SET  ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
		
			 
			 strcat(command," Name = '");
			 strcat(command,TFirstName);
			 strcat(command," ");
			 strcat(command,TLastName);
			 strcat(command,"', Degree = '");
			 strcat(command,TDegree);
			 strcat(command,"' , YearsTaught = ");
			 strcat(command,TYearsTaught);
			
			 strcat(command,"  WHERE Id = ");
			 strcat(command,TId);
			 strcat(command,";");
			 printf("%s\n",command);
			 sql = command;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("Teacher edited successfully\n");
   			}
			
		}
		else if(choice ==14){//find club
			char CId[10] ;
			char CSport[30] ;
			char CCompetitive[30];
			char CLeisure[30];
			char CLeader[2];
			
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			printf("enter the Sport: ");
			scanf("%s", CSport);
			
			printf("enter the Competitive: ");
			scanf("%s", CCompetitive);
			
			printf("enter the Leisure: ");
			scanf("%s", CLeisure);
			
			printf("enter Leader Id: ");
			scanf("%s", CLeader);
			
			char command[100] = "UPDATE Teacher SET  ";
			 //sql = "INSERT INTO Student(Id, Name, Email, Year, VolHours, Gender) VALUES( ";
		
			 
			 strcat(command," Sports = '");
			 strcat(command,CSport);
			 strcat(command,"', Competitve = '");
			 strcat(command,CCompetitive);
			 strcat(command,"', Leisure = '");
			 strcat(command,CLeisure);
			 strcat(command,"' , Leader = '");
			 strcat(command, CLeader);
			
			 strcat(command,"'  WHERE Id = ");
			 strcat(command,CId);
			 strcat(command,";");
			 printf("%s\n",command);
			 sql = command;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("Teacher edited successfully\n");
   			}
		
		}
		else if(choice ==15){//find/edit behaviour of student
		
		}
		else if(choice ==16){//delete student
			char CId[10] ;
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			char Ccommand[100] = "DELETE FROM Student WHERE Id = " ;
			 
			 strcat(Ccommand,CId);
			 strcat(Ccommand,";");
			 printf("%s\n",Ccommand);
			 
			 sql = Ccommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("Student deleted successfully\n");
   			}
			
		
		}
		else if(choice ==17){//delete teacher
			char CId[10] ;
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			char Ccommand[100] = "DELETE FROM Teacher WHERE Id = " ;
			 
			 strcat(Ccommand,CId);
			 strcat(Ccommand,";");
			 printf("%s\n",Ccommand);
			 
			 sql = Ccommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("teacher deleted successfully\n");
   			}
			
		
		}
		else if(choice ==18){//delete club
			char CId[10] ;
		
			printf("\n\nenter the id: ");
			scanf("%s", CId);
			
			char Ccommand[100] = "DELETE FROM Extracurriculars WHERE Id = " ;
			 
			 strcat(Ccommand,CId);
			 strcat(Ccommand,");");
			 printf("%s\n",Ccommand);
			 
			 sql = Ccommand;
			 

   			//execute SQL statement
   			r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      			
   			if( r != SQLITE_OK ){
       			printf("SQL error: %s\n", errMsg);
       			sqlite3_free(errMsg);
   			} 
   			else {
       			printf("club deleted successfully\n");
   			}
			
			
		}
		
		
		else{
			printf("not a choice, try again\n");
		}
		
	
	}
   /*
   sql = "INSERT INTO Movie(Id, Title) VALUES(330, 'Psycho');";

   //execute SQL statement
   r = sqlite3_exec(db, sql, NULL, 0, &errMsg);
      
   if( r != SQLITE_OK ){
       printf("SQL error: %s\n", errMsg);
       sqlite3_free(errMsg);
   } 
   else {
       printf("Movie inserted successfully\n");
   }*/

   

   sqlite3_close(db);
}

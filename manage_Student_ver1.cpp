// use static array

#include<iostream>
#include<cstring>

#define MAX_STUDENTS 100
#define LENGTH_NAME 30 

using namespace std;

int number_Students=0;
char name[MAX_STUDENTS][LENGTH_NAME];
char lastName[MAX_STUDENTS][LENGTH_NAME];

void menu(){
   cout <<"Menu" <<endl;
   cout<<"1. Bo sung danh sach "<<endl;
   cout << "2. Sap xep danh sach "<<endl;
   cout << "3. In danh sach "<<endl;
   cout << "Bam phim 1-3 de chon, phim bat ki # de end"<< endl;
}
// Character String
void swap_Student1(char name1[30], char name2[30]){
   char temp_Name[30];
   strcpy(temp_Name,name1);
   strcpy(name1,name2);
   strcpy(name2,temp_Name);
}
void add_Student1(){
   cout <<"Nhap so hoc sinh:" <<endl;
   cin >> number_Students;
   cout <<"Nhap ten:" <<endl;
   fflush(stdin);
   for (int i = 0; i < number_Students; i++)    
   {
     cin.getline(name[i], 30);     // over 30 character will drop infinitive loop -> need fix
   }
}

void standardized_Name(){
   for(int i=0; i< number_Students; i++){
      int length_before = strlen(name[i]);
      int count_WrongChar =0;
      //danh dau'
       for(int j=0; j< (length_before-1); j++){
          if((name[i][j] == name[i][j+1]) && (name[i][j] == ' ' )){
             name[i][j] = '*';  
          }
       }
      //
      int length_temp = length_before-1; 
      while(length_temp >=0){
         if(name[i][length_temp] == '*'){
            for(int k= length_temp; k < (length_before - 1); k++){
               name[i][k] = name[i][k+1];
            }
            count_WrongChar++;
         }
         length_temp--;
      }
      //check space in the first character
      if(name[i][0] == ' '){
         for(int l = 0; l<(length_before - 1); l++)
            name[i][l] = name[i][l+1];
         count_WrongChar++;  
      }
      //delete wrong char (check space in the last string)
      if(name[i][length_before-1] == ' ')
      name[i][length_before - count_WrongChar -1] = '\0';
      else name[i][length_before - count_WrongChar] = '\0' ;
    }                     
}

void International_Sort_List1(){
   for(int i=0; i< number_Students; i++){
      for(int j=i+1; j<number_Students; j++){
         if(strcmp(name[i], name[j])>0 )
         swap_Student1(name[i], name[j]);
      }
   }
}
void filter_Name1(){
   for(int i=0; i<MAX_STUDENTS; i++){
      for(int j= strlen(name[i]); j>=0; j--){
         if (name[i][j] == ' ' )
         {
            int k=j;
            for(int l=0; l  < (strlen(name[i])-k-1); l++ )
            lastName[i][l] = name[i][k+1+l];
            break;
         }
      }
   }
}
void VN_Sort_List1(){
    for(int i=0; i< number_Students; i++){
      for(int j=i+1; j<number_Students; j++){

         if(strcmp(lastName[i], lastName[j]) >=0 ){

            if(strcmp(lastName[i], lastName[j]) ==0){

               if(strcmp(name[i], name[j])>0 ){
                  swap_Student1(name[i], name[j]);
                  swap_Student1(lastName[i], lastName[j]);
               }
            }else{
               swap_Student1(name[i], name[j]);
                  swap_Student1(lastName[i], lastName[j]);
            }
         }
      }
    }   
}
void print_List1(){
   cout << "Here is current list students" <<endl;
   for(int i=0; i< number_Students; i++){
      for(int j=0; j< strlen(name[i]); j++){
         if(name[i][j]==' ') name[i][j] ='*';
      }
      cout << i+1 <<".  " << name[i] <<"+" <<lastName[i] << endl;
   }
}

// String Class
  
int main(){
   int kT=0;

   do{
      menu();
      cin >> kT;      
      switch (kT)
      {
      case 1:
         add_Student1();
         standardized_Name();
         break;
      case 2:
         int kT1;
         cout <<"Moi ban chon kieu sap xep:" <<endl;
         cout <<"1. Sap xep theo kieu nuoc ngoai." <<endl;
         cout <<"2. Sap xep theo kieu VN." <<endl;
         cin >> kT1;
         while( (kT1 != 1) && (kT1 != 2)){
            cout <<"Moi nhap lai:" << endl;
            cin >> kT1;
         }
         if(kT1 == 1){
            International_Sort_List1();
         }else{
            filter_Name1();
            VN_Sort_List1();
         }
         break;
      case 3:
         print_List1();
         break;
      default:
         break;
      }
   }while(kT==1 || kT==2 || kT == 3);

   return 0;
}


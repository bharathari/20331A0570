#include<stdio.h>

#include<stdlib.h>
struct student
{
 int rollno;
 char name[30];
 float mark;
}s;
// FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no :");
 scanf("%d", &s.rollno);
 printf("Enter the Name :");
 scanf("%s",s.name);
 printf("Enter the mark :");
 scanf("%f", &s.mark);
 fwrite(&s, sizeof(s), 1, fp);
 fclose(fp);
}
// FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\tMark\n\n");
 while (fread(&s, sizeof(s), 1, fp1))
 printf(" %d\t\t%s\t%.2f\n", s.rollno, s.name, s.mark);
 fclose(fp1);
}
int avlrollno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&s, sizeof(s), 1, fp);

  if (rno == s.rollno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
// FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 FILE *fp2;
 int r, sn, avl;
 printf("\nEnter the Roll no you want to search :");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
  printf("Roll No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&s, sizeof(s), 1, fp2))
  {
   sn = stud.rollno;
   if (sn == r)
   {
    printf("\nRoll no = %d", s.rollno);
    printf("\nName = %s", s.name);
    printf("\nMark = %.2f\n", s.mark);
   }
  }
  fclose(fp2);
 }
}
// FUNCTION TO DELETE A RECORD


void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, sp;
 printf("Enter the Roll no you want to delete :");
 scanf("%d", &r);
 if (avlrollno(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&s, sizeof(s), 1, fpo))
  {
   sp = stud.rollno;
   if (sp != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&s, sizeof(s), 1, fpt))
   fwrite(&s, sizeof(s), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
// FUNCTION TO UPDATE THE RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int sp, r, ch;
 printf("Enter roll number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
 {
  printf("Roll number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&s, sizeof(s), 1, fpo))
  {
   sp = s.rollno;
   if (sp != r)
    fwrite(&s, sizeof(s), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of Roll Number %d", r);
    printf("\n\t2. Update Mark of Roll Number %d", r);
    printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s",s.name);
     break;
    case 2:
     printf("Enter Mark : ");
     scanf("%f", &s.mark);
     break;
    case 3:
     printf("Enter Name: ");
     scanf("%s",s.name);
     printf("Enter Mark: ");
     scanf("%f", &s.mark);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&s, sizeof(s), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&s, sizeof(s), 1, fpt))
  {
   fwrite(&s, sizeof(s), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}
/* FUNCTION TO SORT THE RECORD */
void sort()
{
 int a[20], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("Record", "r");
 while (fread(&s, sizeof(s), 1, fpo))
 {
  a[count] = s.rollno;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
 printf("Roll No.\tName\t\tMark\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&s, sizeof(s), 1, fpo))
  {
   if (a[i] == s.rollno)
    printf("\n %d\t\t %s \t\t %2f",s.rollno, s.name, s.mark);
  }

 }
}
// FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //

//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&s, sizeof(s), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
int main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
   else
    sort();
   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}

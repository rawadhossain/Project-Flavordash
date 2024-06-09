#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "sha256.h"

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define HASH_LENGTH 64

struct User
{
     char username[MAX_USERNAME_LENGTH];
     char passwordHash[HASH_LENGTH + 1]; // +1 for null terminator
};

void Applycoupon();
void signUp(struct User users[], int *numUsers);
bool login(struct User users[], int numUsers);
void hashPassword(const char *password, char *hash);

void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void generate_invoice(char foodname[25], int quantity, float price, char username[50], char address[100], char phone[15]);

void write_review(char foodname[25]);
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

void deletefood(int serial);
int countitem();

void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);

struct Node
{

     char foodname[50];
     int quantity;
     float price;
     int data;
     struct Node *next;
};

typedef struct Node node;

node *head, *list;
char username[50];
char address[100];
char phone[15];
int main()
{

     system(">>>>>>>>>>> FOOD ORDERING MANAGEMENT SYSTEM <<<<<<<<<<<<");
     system("mode con: cols=80 lines=30");

     // loadingbar();
     Circularloadingbar();
     cls();
     pwellcome();
     // newWelcome();
     Sleep(300);
     cls();

     int c = 0;
     int v = 0;
     int any;
     char coupon[50];
     int cardno[100];
     float cardmoney[100];
     float totalmoney = 0;
     int total_order[100];
     int order_quantity[100];
     int order = 0;
     int uquantity;
     int citem;

     head = NULL;
     insertfirst(5, "Burger      ", 23, 220.00);
     insertend(6, "Pizza       ", 13, 350.00);
     insertend(1, "CheeseCake  ", 18, 175.00);
     insertend(2, "Coffee      ", 46, 325.00);
     insertend(3, "Ice cream   ", 46, 230.00);
     insertend(4, "Sandwich    ", 34, 320.00);
     insertend(7, "Grill       ", 17, 100.00);
     insertend(8, "Fries       ", 75, 350.00);
     insertend(9, "Cold Drinks ", 73, 120.00);

userlogin:
     br(1);
     userloginfun();
     br(1);
     pre(4);
     cls();
     fflush(stdin);

mainmenu:
     br(1);
     main_menu();
     int main_menu_choice;

     br(1);
     pre(4);
     fflush(stdin);
     scanf("%d", &main_menu_choice);

     if ((main_menu_choice >= 1 && main_menu_choice <= 4))
     {
          if (main_menu_choice == 1)
          {
          foodlist:

               cls();
               printf("=> 0. Main Menu ");
               foodlist();
          }

          else if (main_menu_choice == 2)
          {
               int admin_panel_choice;
          adminpanelchoice:

               cls();
               middle1();
               pre(4);
               printf("1. Main Menu\n\n\t");
               Sleep(300);
               printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");

               fflush(stdin);

               int p = 0;
               char password[20];
               do
               {
                    password[p] = getch();
                    if (password[p] != '\r')
                    {
                         printf("*");
                    }
                    p++;
               } while (password[p - 1] != '\r');
               password[p - 1] = '\0';

               if (strcmp(password, "1234") == 0)
               {
                    node *temp;
                    temp = list;

               adminchoise:
                    cls();
                    br(5);
                    pre(4);
                    echo("\tAdmin Pannel:\n\n");
                    pre(4);
                    printf(" 1. Total Cash \n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 2. View Card Pay \n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 3. Add Food Item\n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 4. Remove Food Item \n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 5. View Food List \n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 6. Item Counter \n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 7. System Backup\n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 8. Order Preview\n\n");
                    Sleep(250);
                    pre(4);
                    printf(" 0. Main Menu ");
                    Sleep(250);

                    int adminchoise;

                    fflush(stdin);
                    scanf("%d", &adminchoise);

                    if (adminchoise == 1)
                    {
                         cls();
                         middle1();
                         pre(4);
                         printf("Todays Total Cash : %0.2f  \n", totalmoney);

                         Sleep(2000);

                         goto adminchoise;
                    }
                    else if (adminchoise == 2)
                    {

                         if (c != 0)
                         {
                              cls();
                              br(3);
                              pre(4);

                              printf(" ____________________________\n");
                              pre(4);
                              printf("|   Card NO.   |   Money    |\n");
                              pre(4);
                              printf("------------------------------\n");
                              pre(4);

                              for (int z = 1; z <= c; z++)
                              {

                                   printf("|  %d  | %0.2f |\n", cardno[z], cardmoney[z]);
                                   pre(4);
                                   printf("------------------------------\n");
                                   pre(4);
                                   Sleep(450);
                              }
                              Sleep(1500);
                         }

                         if (c == 0)
                         {

                              cls();
                              middle1();
                              pre(4);
                              printf("No Card History\n");
                         }
                         Sleep(1500);
                         goto adminchoise;
                    }

                    else if (adminchoise == 3)
                    {

                    foodadd:
                         cls();

                         char ffoodname[25];
                         int fquantity;
                         int fdata;
                         float fprice;
                         int fposi;

                         br(3);
                         pre(4);
                         printf(" Enter Food Name :  ");

                         fflush(stdin);
                         scanf("%[^\n]s", ffoodname);
                    fquantity:
                         fflush(stdin);

                         br(2);
                         pre(4);
                         printf(" Enter Food Quantity :  ");

                         scanf("%d", &fquantity);
                         fflush(stdin);

                    foodserial:
                         br(2);
                         pre(4);
                         printf(" Enter Food Serial :  ");
                         scanf("%d", &fdata);
                         node *exist;
                         exist = list;
                         while (exist->data != fdata)
                         {
                              if (exist->next == NULL)
                              {
                                   break;
                              }
                              exist = exist->next;
                         }
                         if (exist->data == fdata)
                         {
                              cls();
                              br(5);
                              pre(3);
                              printf(" Food Serial Already Exist, Please Re-Enter  ");
                              Sleep(2000);
                              goto foodserial;
                         }

                    fprice:
                         fflush(stdin);

                         br(2);
                         pre(4);
                         printf(" Enter Food Price :  ");
                         fflush(stdin);

                         scanf("%f", &fprice);

                         br(2);
                         pre(4);
                         printf("Submiting your data");
                         for (int cs = 0; cs < 4; cs++)
                         {
                              printf(" .");
                              Sleep(500);
                         }

                         insertend(fdata, ffoodname, fquantity, fprice);

                         br(2);
                         pre(4);
                         printf("Adding Food  Successfull....\n");

                         Sleep(2000);

                         goto adminchoise;
                    }
                    else if (adminchoise == 4)
                    {

                         cls();
                         middle1();
                         pre(2);
                         printf("Enter Serial No of the Food To Delete : ");
                         int fdelete;
                    fdelete:

                         fflush(stdin);
                         scanf("%d", &fdelete);
                         node *temp;
                         temp = list;
                         while (temp->data != fdelete)
                         {
                              temp = temp->next;
                         }
                         if (temp->data == fdelete)
                         {
                              deletefood(fdelete);
                         }
                         else
                         {
                              br(2);
                              pre(2);
                              printf("Please Enter Correct Number :  ");
                              Sleep(500);
                              goto fdelete;
                         }

                         goto adminchoise;
                    }

                    else if (adminchoise == 5)
                    {

                         cls();
                         foodlist();
                         Sleep(1000);

                         br(2);
                         pre(4);
                         printf("1. <-- back  \n\n");
                         pre(5);

                         fflush(stdin);
                         scanf("%d", &any);

                         goto adminchoise;
                    }

                    else if (adminchoise == 6)
                    {

                         citem = countitem();
                         cls();
                         for (int cs = 1; cs <= citem; cs++)
                         {
                              middle1();
                              pre(4);
                              printf("Item Counting ");
                              printf(" %d ", cs);
                              Sleep(150);
                              cls();
                         }
                         cls();
                         middle1();
                         pre(4);
                         printf("Total Food Item is --> %d  \n", citem);
                         Sleep(2000);
                         goto adminchoise;
                    }

                    /// Backup System
                    else if (adminchoise == 7)
                    {

                         char date[35] = __DATE__;

                         strcat(date, ".txt");
                         FILE *fptr;
                         fptr = fopen(date, "w");
                         backuploader();
                         if (fptr == NULL)
                         {
                              br(3);
                              pre(3);
                              printf("Error!");
                              Sleep(500);
                              goto adminchoise;
                         }
                         fprintf(fptr, "Total Cash Today : %0.2f\n\n\n", totalmoney);
                         fprintf(fptr, "Card No ------- Money \n\n");
                         for (int l = 1; l <= c; l++)
                         {
                              fprintf(fptr, "%d ------- %0.2f \n", cardno[l], cardmoney[l]);
                         }
                         br(2);
                         pre(4);
                         printf("Backup Successfull...");
                         Sleep(1500);

                         fclose(fptr);
                         goto adminchoise;
                    }
                    else if (adminchoise == 8)
                    {

                         cls();
                         br(2);
                         pre(2);
                         ccolor(40);
                         printf("\n\t\t");
                         ccolor(240);
                         printf("______________________________________________________ ");
                         ccolor(40);
                         printf("\n\t\t");
                         ccolor(240);
                         printf("|  Order No.  |    Name   |  Quantity |  In Stock  |");
                         ccolor(40);
                         printf("\n\t\t");
                         ccolor(240);
                         printf("-------------------------------------------------------");
                         ccolor(40);
                         for (int o = 1; o <= order; o++)
                         {
                              order_view(total_order[o], order_quantity[o], o);
                         }

                         br(2);
                         pre(4);
                         printf("1. <-- back  \n\n");
                         pre(5);

                         fflush(stdin);
                         scanf("%d", &any);

                         goto adminchoise;
                    }
                    else if (adminchoise == 0)
                    {

                         goto mainmenu;
                    }

                    else
                    {
                         br(2);
                         pre(4);
                         printf("Please Select From List :  ");
                         Sleep(500);
                         goto adminchoise;
                    }
               }

               else if (admin_panel_choice == 1)
               {
                    goto mainmenu;
               }
               else
               {
                    br(2);
                    pre(4);
                    printf("Please Enter Correct Choice");
                    goto adminpanelchoice;
               }
          }

          else if (main_menu_choice == 3)
          {
               cls();
               middle1();
               pre(3);
               printf("Thank You For Using Our System \n\n\n\n\n\n\n");
               Sleep(1000);

               exit(1);
          }

          // food review
          else if (main_menu_choice == 4)
          {
               FILE *file = fopen("reviews.txt", "r");
               if (file == NULL)
               {
                    printf("Unable to open reviews file.\n");
                    return;
               }

               char review[256];
               cls();
               middle1();
               pre(3);
               printf("Food Reviews:\n\n");
               while (fgets(review, sizeof(review), file))
               {
                    printf("%s", review);
               }
               fclose(file);
               br(2);
               pre(4);
               printf("\nPress 1 to return to main menu...");
               int i;
               scanf("%d", &i);
               if (i == 1)
                    goto mainmenu;
          }
     }

     else
     {
          br(2);
          pre(4);
          printf("Please Enter Correct Choice");
          Sleep(300);
          goto mainmenu;
     }

     int get_food_choice;

     br(2);
     pre(3);
     fflush(stdin);
     printf("Place Your Order: ");
     scanf("%d", &get_food_choice);

     if (get_food_choice == 0)
     {
          goto mainmenu;
     }

     node *temp;

     temp = list;

     while (temp->data != get_food_choice)
     {

          temp = temp->next;
          if (temp == NULL)
          {
               br(2);
               pre(4);
               echo("Please Choice From List ");
               br(2);
               Sleep(1000);
               goto foodlist;
          }
     }
     if (get_food_choice == temp->data)
     {

     fcquantity:
          br(2);
          pre(4);
          printf("Enter Food Quantity : ");

          int fcquantity;

          fflush(stdin);
          scanf("%d", &fcquantity);
          cls();

          if (fcquantity == 0)
          {
               cls();
               middle1();
               pre(3);
               printf("Quantity Can not be Zero ");
               Sleep(2000);
               cls();
               goto foodlist;
          }
          else if (fcquantity > temp->quantity)
          {
               cls();
               middle1();
               pre(3);
               printf("Out of Stock ! ");
               Sleep(2000);

               goto foodlist;
          }

          middle1();
          pre(4);
          printf("Choice food:  %s  \n", temp->foodname);
          pre(4);
          printf("Total Price: Tk. %0.2f \n\n", temp->price * fcquantity);
          pre(4);
          printf("1. Confirm to buy this \n\n");
          pre(4);
          printf("2. Food List  ");
          int confirm;
     confirm:

          fflush(stdin);
          scanf("%d", &confirm);

          if (confirm == 1)
          {

               br(2);
               pre(4);
               printf(" 1. Cash ");
               br(2);
               pre(4);
               printf(" 2. Credit ");
               br(2);
               pre(4);
               printf(" 3. IUT Wallet \n");
               int payment;
          payment:

               fflush(stdin);
               scanf("%d", &payment);

               // Cash

               if (payment == 1)
               {
                    cls();
                    middle1();
                    pre(4);
                    float discount = 0.1; // 10% discount
                    Applycoupon();

                    br(2);
                    pre(4);
                    printf("Enter coupon: ");
                    scanf("%s", coupon);
                    br(2);
                    pre(4);

                    if (strcmp(coupon, "FLAVOR10") == 0)
                    {
                         printf("Coupon Succesfully Entered. Proceeding...\n\n");
                         Sleep(1000);

                         totalmoney += temp->price * fcquantity;
                         pre(4);
                         printf("Discount amount : %.2f  \n", discount * temp->price * fcquantity);
                         totalmoney -= discount * temp->price * fcquantity;
                         pre(4);

                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;
                         updatefood(get_food_choice, uquantity);
                         printf("Total money : %.2f \n\n", totalmoney);

                         pre(4);
                         printf("Press 1 to continue...\n\n");
                         int a;
                         printf("\n");
                         pre(4);
                         scanf("%d", &a);
                         if (a == 1)
                         {
                              cls();
                              middle1();
                              pre(4);
                              loadingbar();
                              br(2);
                              pre(4);
                              printf("\t\t===>THANK YOU<===");
                              br(2);
                              pre(4);
                              generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                              br(2);
                              pre(4);
                              printf("\tFood Ordered Successfully ...");
                              br(2);
                              pre(4);
                              printf("1. Do you want to buy any other item? ");
                              br(2);
                              pre(4);
                              printf("2. Main Menu ");
                              br(2);
                              pre(4);
                              printf("3. Write Review ");
                         }
                    }
                    else
                    {
                         totalmoney += temp->price * fcquantity;
                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;

                         updatefood(get_food_choice, uquantity);
                         br(1);
                         pre(4);
                         printf("Incorrect Coupon!");
                         br(1);
                         pre(4);
                         printf("Total Price : Tk. %.2f \n\n", totalmoney);
                         pre(4);
                         printf("Press 1 to continue...\n\n");
                         int a;
                         pre(4);
                         printf("\n");
                         scanf("%d", &a);
                         if (a == 1)
                         {
                              cls();
                              middle1();
                              pre(4);
                              generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                              br(2);
                              pre(4);
                              printf("\t    ===>THANK YOU<===");
                              br(2);
                              pre(4);
                              printf("Food Ordered Successfully ...");
                              br(2);
                              pre(4);
                              printf("1. Do you want to buy any other item? ");
                              br(2);
                              pre(4);
                              printf("2. Main Menu \n");
                              br(2);
                              pre(4);
                              printf("3. Write Food Review ");
                         }
                    }

                    int ps_menu;
               psmenu:

                    fflush(stdin);
                    scanf("%d", &ps_menu);

                    if (ps_menu == 1)
                         goto foodlist;
                    else if (ps_menu == 2)
                         goto mainmenu;
                    else if (ps_menu == 3)
                    {
                         write_review(temp->foodname);
                         int j;
                         scanf("%d", &j);
                         if (j == 1)
                              goto mainmenu;
                    }
                    else
                    {
                         br(2);
                         pre(4);
                         printf("Please Choice from list : ");
                         goto psmenu;
                    }
               }

               /// Credit Card Option

               else if (payment == 2)
               {
                    cls();
                    middle1();
                    pre(4);
                    float discount = 0.1; // 10% discount
                    Applycoupon();

                    br(2);
                    pre(4);
                    printf("Enter coupon: ");
                    scanf("%s", coupon);
                    br(2);
                    pre(4);

                    if (strcmp(coupon, "FLAVOR10") == 0)
                    {
                         printf("Coupon Succesfully Entered. Proceeding...\n\n");
                         Sleep(1000);
                         // fflush(stdin);

                         totalmoney += temp->price * fcquantity;
                         pre(4);
                         printf("Discount amount : %.2f  \n", discount * temp->price * fcquantity);
                         totalmoney -= discount * temp->price * fcquantity;
                         pre(4);

                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;
                         updatefood(get_food_choice, uquantity);
                         printf("Total money : %.2f \n\n", totalmoney);

                         pre(4);
                         printf("Press 1 to continue...\n\n");
                         int a;
                         pre(4);
                         printf("\n");
                         scanf("%d", &a);
                         if (a == 1)
                         {
                              int card_number[100];
                              c++;

                              cls();
                              middle1();
                              pre(4);
                              generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                              br(2);
                              pre(4);
                              printf("Enter Your Card No : ");

                              fflush(stdin);
                              scanf("%d", &card_number[c]);

                              cardno[c] = card_number[c];
                              br(2);
                              pre(2);
                              printf("Enter Your Card Pin   : ");

                              fflush(stdin);
                              int p = 0;
                              char pin[20];
                              do
                              {
                                   pin[p] = getch();
                                   if (pin[p] != '\r')
                                        printf("*");
                                   p++;
                              } while (pin[p - 1] != '\r');
                              pin[p - 1] = '\0';
                              getch();

                              cardmoney[c] = temp->price * fcquantity;

                              totalmoney += temp->price * fcquantity;
                              order++;
                              total_order[order] = get_food_choice;
                              order_quantity[order] = fcquantity;

                              uquantity = temp->quantity - fcquantity;

                              updatefood(get_food_choice, uquantity);
                              loadingbar();

                              br(2);
                              pre(4);
                              printf("Payment Success...");
                              br(2);
                              pre(4);
                              printf("1. Do you want to place another order ? ");
                              br(2);
                              pre(4);
                              printf("2. Main Menu ");
                              cls();
                              middle1();
                              pre(4);
                              loadingbar();
                              br(2);
                              pre(4);
                              printf("===>THANK YOU<===");
                              br(2);
                              pre(4);
                              printf("Food Ordered Successfully ...");
                              br(2);
                              pre(4);
                              printf("1. Do you want to buy any other item? ");
                              br(2);
                              pre(4);
                              printf("2. Main Menu ");
                              br(2);
                              pre(4);
                              printf("3. Write Food Review ");
                         }
                    }
                    else
                    {
                         int card_number[100];
                         c++;

                         cardmoney[c] = temp->price * fcquantity;

                         totalmoney += temp->price * fcquantity;
                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;
                         updatefood(get_food_choice, uquantity);

                         cls();
                         middle1();
                         pre(4);
                         printf("\t    No Coupon applied! ");
                         br(2);
                         pre(4);
                         generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                         br(2);
                         pre(4);
                         printf("Enter Your Card No : ");

                         fflush(stdin);
                         scanf("%d", &card_number[c]);

                         cardno[c] = card_number[c];

                         br(2);
                         pre(4);
                         printf("Enter Your Card Pin   : ");

                         fflush(stdin);
                         // scanf("%d",&pin);
                         int p = 0;
                         char pin[20];
                         do
                         {
                              pin[p] = getch();
                              if (pin[p] != '\r')
                              {
                                   printf("*");
                              }
                              p++;
                         } while (pin[p - 1] != '\r');
                         pin[p - 1] = '\0';
                         getch();
                         cls();
                         loadingbar();

                         br(2);
                         pre(4);
                         printf("Payment Success...");
                         br(2);
                         pre(4);
                         printf("1. Do you want to place another order ? ");
                         br(2);
                         pre(4);
                         printf("2. Main Menu ");
                         br(2);
                         pre(4);
                         printf("3. Write Food Review ");
                    }

                    int ps_menu2;
               psmenu2:

                    scanf("%d", &ps_menu2);
                    if (ps_menu2 == 1)
                         goto foodlist;
                    else if (ps_menu2 == 2)
                         goto mainmenu;
                    else if (ps_menu2 == 3)
                    {
                         write_review(temp->foodname);
                         int j;
                         scanf("%d", &j);
                         if (j == 1)
                              goto mainmenu;
                    }
                    else
                    {
                         br(2);
                         pre(4);
                         printf("Please Choice from list : ");
                         goto psmenu2;
                    }
               }

               // IUT Wallet
               else if (payment == 3)
               {
                    cls();
                    middle1();
                    pre(4);
                    float discount = 0.1; // 10% discount
                    Applycoupon();

                    br(2);
                    pre(4);
                    printf("Enter coupon: ");
                    scanf("%s", coupon);
                    br(2);
                    pre(4);
                    if (strcmp(coupon, "FLAVOR10") == 0)
                    {
                         printf("Coupon Succesfully Entered. Proceeding...\n\n");
                         Sleep(1000);
                         // fflush(stdin);

                         totalmoney += temp->price * fcquantity;
                         pre(4);
                         printf("Discount amount : %.2f  \n", discount * temp->price * fcquantity);
                         totalmoney -= discount * temp->price * fcquantity;
                         pre(4);

                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;
                         updatefood(get_food_choice, uquantity);
                         printf("Total money : %.2f \n\n", totalmoney);

                         pre(4);
                         printf("Press 1 to continue...\n\n");
                         int a;
                         pre(4);
                         printf("\n");
                         scanf("%d", &a);
                         if (a == 1)
                         {
                              int iut_card[100];
                              c++;
                              cardmoney[c] = temp->price * fcquantity;
                              totalmoney += temp->price * fcquantity;
                              order++;
                              total_order[order] = get_food_choice;
                              order_quantity[order] = fcquantity;
                              uquantity = temp->quantity - fcquantity;
                              updatefood(get_food_choice, uquantity);

                              cls();
                              middle1();
                              pre(4);
                              generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                              br(2);
                              pre(4);
                              printf("Enter Your ID : ");
                              scanf("%d", &iut_card[c]);
                              fflush(stdin);

                              cardno[c] = iut_card[c];

                              br(2);
                              pre(4);
                              fflush(stdin);

                              loadingbar();

                              br(2);
                              pre(4);
                              printf("Payment Success...");
                              br(2);
                              pre(4);
                              printf("1. Do you want to place another order ? ");
                              br(2);
                              pre(4);
                              printf("2. Main Menu \n");
                              br(2);
                              pre(4);
                              printf("3. Write Food Review ");
                         }
                    }
                    else
                    {
                         int iut_card[100];
                         c++;
                         cardmoney[c] = temp->price * fcquantity;
                         totalmoney += temp->price * fcquantity;
                         order++;
                         total_order[order] = get_food_choice;
                         order_quantity[order] = fcquantity;
                         uquantity = temp->quantity - fcquantity;
                         updatefood(get_food_choice, uquantity);

                         cls();
                         middle1();
                         pre(4);
                         printf("\t\t   No Coupon applied! ");
                         br(2);
                         pre(4);
                         generate_invoice(temp->foodname, fcquantity, totalmoney, username, address, phone);
                         br(2);
                         pre(4);
                         printf("Enter Your ID : ");

                         fflush(stdin);
                         scanf("%d", &iut_card[c]);

                         cardno[c] = iut_card[c];

                         br(2);
                         pre(4);
                         fflush(stdin);

                         loadingbar();

                         br(2);
                         pre(4);
                         printf("Payment Success...");
                         br(2);
                         pre(4);
                         printf("1. Do you want to place another order ? ");
                         br(2);
                         pre(4);
                         printf("2. Main Menu ");
                         br(2);
                         pre(4);
                         printf("3. Write Food Review ");
                    }
                    int ps_menu3;
               psmenu3:

                    scanf("%d", &ps_menu3);

                    if (ps_menu3 == 1)
                         goto foodlist;

                    else if (ps_menu3 == 2)
                         goto mainmenu;
                    else if (ps_menu3 == 3)
                    {
                         write_review(temp->foodname);
                         int j;
                         scanf("%d", &j);
                         if (j == 1)
                              goto mainmenu;
                    }
                    else
                    {
                         br(2);
                         pre(4);
                         printf("Please Choice from list : ");
                         goto psmenu3;
                    }
               }

               else
               {
                    br(2);
                    pre(4);
                    printf("Enter Choice from List : ");
                    goto payment;
               }
          }

          else if (confirm == 2)
               goto foodlist;

          else
          {
               br(2);
               pre(4);
               printf("Enter Choise from List : ");
               goto confirm;
          }
     }

     else
     {
          br(2);
          pre(4);
          echo("Please Choice From List ");
          br(2);
          Sleep(300);
          goto foodlist;
     }
}

void cls()
{

     system("cls");
}

void echo(char print[])
{

     printf("%s", print);
}

void br(int line)
{
     for (int i = 0; i < line; i++)
     {
          printf("\n");
     }
}

void pre(int tab)
{

     for (int i = 0; i < tab; i++)
     {
          printf("\t");
     }
}

void span(int space)
{

     for (int i = 0; i < space; i++)
     {
          printf(" ");
     }
}

void main_menu()
{

     cls();
     br(5);
     pre(3);
     echo("===> 1. Food List");
     Sleep(400);
     br(2);
     pre(3);
     echo("===> 2. Admin Panel");
     Sleep(400);
     br(2);
     pre(3);
     echo("===> 3. Exit");
     Sleep(400);
     br(2);
     pre(3);
     echo("===> 4. Food Reviews");
     Sleep(400);
     //   br(2); pre(3); echo("=> 4. Admin Panel");  Sleep(400);

     br(1);
}

void insertend(int data, char foodname[25], int quantity, float price)
{

     node *temp;

     temp = (node *)malloc(sizeof(node));

     temp->data = data;

     temp->price = price;

     temp->quantity = quantity;

     strcpy(temp->foodname, foodname);

     temp->next = NULL;

     if (head == NULL)
     {
          head = temp;
          list = head;
     }
     else
     {

          while (head->next != NULL)
          {
               head = head->next;
          }

          head->next = temp;
     }
}

void insertfirst(int data, char foodname[25], int quantity, float price)
{

     node *temp;

     temp = (node *)malloc(sizeof(node));

     temp->data = data;

     temp->price = price;

     strcpy(temp->foodname, foodname);

     temp->quantity = quantity;

     temp->next = head;

     head = temp;

     list = head;
}

void insertmid(int pos, int data, char foodname[25], int quantity, float price)
{

     node *temp;

     temp = (node *)malloc(sizeof(node));

     temp->data = data;

     temp->price = price;

     temp->quantity = quantity;

     strcpy(temp->foodname, foodname);

     while (head->next->data != pos)
     {

          head = head->next;
     }

     temp->next = head->next;
     head->next = temp;

     //    free(temp);
}

void deletefood(int serial)
{

     node *temp;
     temp = (node *)malloc(sizeof(node));

     temp = list;

     if (temp->data != serial)
     {

          while (temp->next->data != serial)
          {
               temp = temp->next;
          }

          if (temp->next->data == serial)
          {

               temp->next = temp->next->next;
               cls();
               printf("\n\n\n\n\t\t\tDeleting Item %d ", serial);
               for (int cs = 0; cs < 4; cs++)
               {
                    printf(" .");
                    Sleep(400);
               }

               printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
               Sleep(500);
          }
          else
          {
               printf("\n\n\n\n\t\t\tFood Item Not Found\n");
               Sleep(500);
          }

          head = temp;
     }
     else
     {

          temp = temp->next;
          cls();
          printf("\n\n\n\n\t\t\tDeleting Item %d ", serial);
          for (int cs = 0; cs < 4; cs++)
          {
               printf(" .");
               Sleep(400);
          }

          printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
          Sleep(500);

          head = temp;

          list = head;
     }
}

void updatefood(int udata, int uquantity)
{

     node *temp;
     temp = list;

     while (temp->data != udata)
     {
          temp = temp->next;
     }
     if (temp->data == udata)
     {
          temp->quantity = uquantity;
     }
}

int countitem()
{

     node *temp;

     temp = list;

     int countitem = 0;

     if (temp == NULL)
     {
          countitem = 0;
     }
     else
     {
          countitem = 1;
          while (temp->next != NULL)
          {
               countitem++;
               temp = temp->next;
          }
     }

     return countitem;
}

void foodlist()
{

     ccolor(40);

     printf("\n\t\t");
     ccolor(240);
     printf("_________________________________________________________ ");
     ccolor(40);
     printf("\n\t\t");
     ccolor(240);
     printf("|  Food No.  |   FooD Name      |    Price    | In Stock |");
     ccolor(40);
     printf("\n\t\t");
     ccolor(240);
     printf("----------------------------------------------------------");
     ccolor(40);

     node *temp;

     temp = list;

     while (temp != NULL)
     {

          ccolor(40);

          printf("\n\t\t");
          ccolor(62);
          printf("|     %d      |    %s  |    %0.2f   |   %d     |", temp->data, temp->foodname, temp->price, temp->quantity);
          ccolor(40);
          printf("\n\t\t");
          ccolor(62);
          printf("----------------------------------------------------------");

          temp = temp->next;
          Sleep(100);
     }

     ccolor(40);

     //  free(temp);
}

void order_view(int order, int quantity, int or_no)
{

     ccolor(40);

     node *temp;

     temp = list;

     while (temp->data != order)
     {

          temp = temp->next;
     }
     if (temp->data == order)
     {

          ccolor(40);

          printf("\n\t\t");
          ccolor(62);
          printf("|     %d      |    %s  |     %d     |     %d     |", or_no, temp->foodname, quantity, temp->quantity);
          ccolor(40);
          printf("\n\t\t");
          ccolor(62);
          printf("-------------------------------------------------------");

          Sleep(100);
     }

     ccolor(40);
}

void ccolor(int clr)
{
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, clr);
}

/// HERE PRINTF STYLE FUNCTION

void pwellcome()
{
     ccolor(40);

     char welcome[50] = "WELCOME";
     char welcome2[50] = " TO ";
     char welcome3[50] = " FLAVORDASH: ";
     char welcome4[50] = " IUT'S DELIVERY HUB";
     printf("\n\n\n\n\n\t\t\t");
     for (int wlc = 0; wlc < strlen(welcome); wlc++)
     {
          ccolor(120 + (wlc * 9));

          printf(" %c", welcome[wlc]);
          Sleep(200);
     }
     ccolor(40);
     printf("\n\n\t\t\t\t ");
     for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
     {
          ccolor(160 + (wlc2 * 9));

          printf(" %c", welcome2[wlc2]);
          Sleep(200);
     }
     ccolor(40);
     printf("\n\n\n\t\t\t ");
     for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++)
     {
          if (welcome3[wlc3] != 'D')
          {
               ccolor(121 + (wlc3 * 4));

               printf(" %c", welcome3[wlc3]);
          }
          else
          {
               ccolor(11);

               printf(" %c", welcome3[wlc3]);
          }

          Sleep(200);
     }
     ccolor(40);
     printf("\n\n\n\t\t\t\t ");
     for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++)
     {
          if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E')
          {
               ccolor(121 + (wlc3 * 4));

               printf(" %c", welcome4[wlc3]);
          }
          else
          {
               ccolor(11);

               printf(" %c", welcome4[wlc3]);
          }
          Sleep(200);
     }
     ccolor(40);
}

void newWelcome()
{
     ccolor(40);

     char welcome[] = "WELCOME";
     char welcome2[] = " TO ";
     char welcome3[] = " FLAVORDASH: ";
     char welcome4[] = " MANAGEMENT SYSTEM";

     printf("\n\n\n\n\n\t\t\t");

     // Print 'WELCOME' with color transition
     for (int wlc = 0; wlc < strlen(welcome); wlc++)
     {
          ccolor(120 + (wlc * 9));
          printf(" %c", welcome[wlc]);
          Sleep(200);
     }

     ccolor(40);
     printf("\n\n\t\t\t\t ");

     // Print 'TO' with color transition
     for (int wlc2 = 0; wlc2 < strlen(welcome2); wlc2++)
     {
          ccolor(160 + (wlc2 * 9));
          printf(" %c", welcome2[wlc2]);
          Sleep(200);
     }

     ccolor(40);
     printf("\n\n\n\t\t\t ");

     // Print 'FLAVORDASH: ' with color transition for 'D'
     for (int wlc3 = 0; wlc3 < strlen(welcome3); wlc3++)
     {
          if (welcome3[wlc3] != 'D')
          {
               ccolor(121 + (wlc3 * 4));
               printf(" %c", welcome3[wlc3]);
          }
          else
          {
               ccolor(11);
               printf(" %c", welcome3[wlc3]);
          }
          Sleep(200);
     }

     ccolor(40);
     printf("\n\n\n\t\t\t\t ");

     // Print 'MANAGEMENT SYSTEM' with color transition for 'A' and 'E'
     for (int wlc3 = 0; wlc3 < strlen(welcome4); wlc3++)
     {
          if (welcome4[wlc3] != 'A' && welcome4[wlc3] != 'E')
          {
               ccolor(121 + (wlc3 * 4));
               printf(" %c", welcome4[wlc3]);
          }
          else
          {
               ccolor(11);
               printf(" %c", welcome4[wlc3]);
          }
          Sleep(200);
     }
     ccolor(40);
}

void loadingbar(void)
{

     for (int i = 15; i <= 100; i += 3)
     {

          cls();
          ccolor(40);
          printf("\n\n\n\t\t\t\t");

          if (i == 100)
               printf("100%% Loading...\n\n\t\t");

          else
               printf("%d%% Loading...\n\n\t\t", i);

          printf("");

          for (int j = 0; j < i; j += 2)
          {
               ccolor(160 + j);
               printf(" ");
               ccolor(40);
          }
          Sleep(100);
          if (i == 90 || i == 50 || i == 96 || i == 83)
          {
               Sleep(100);
          }
     }
}

void Circularloadingbar(void)
{
     const int centerX = 40;
     const int centerY = 12;
     const int radius = 8;
     const char completedChar = '*';
     const char remainingChar = '.';

     for (int i = 15; i <= 100; i += 3)
     {
          cls();
          ccolor(40);
          printf("\n\n\n\n\n\n\n\t\t\t\t");
          printf("%d %% Loading...\n\n\t\t", i);

          printf("\t");

          for (int y = centerY - radius; y <= centerY + radius; y++)
          {
               for (int x = centerX - radius; x <= centerX + radius; x++)
               {
                    double distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));
                    if (distance <= radius)
                    {
                         if (distance <= radius * i / 100.0)
                         {
                              printf("%c", completedChar);
                         }
                         else
                         {
                              printf("%c", remainingChar);
                         }
                    }
                    else
                    {
                         printf(" ");
                    }
               }
               printf("\n\t\t");
          }

          Sleep(100);
          if (i == 90 || i == 50 || i == 96 || i == 83)
          {
               Sleep(100);
          }
     }
}

void backuploader(void)
{

     for (int i = 15; i <= 100; i += 5)
     {

          cls();
          ccolor(40);

          printf("\n\n\n\n\n\n\n\t\t\t\t");
          printf("%d %% Backing UP DATA...\n\n\t\t", i);

          printf("");

          for (int j = 0; j < i; j += 2)
          {

               ccolor(120 + j);
               printf(" ");
               ccolor(40);
          }
          Sleep(50);
          if (i == 90 || i == 50 || i == 96 || i == 83)
          {
               Sleep(50);
          }
     }
}

void middle1(void)
{

     printf("\n\n\n\n\n\n\n");
}

void middtab1(void)
{
     printf("\t\t\t\t\t");
}

void userloginfun()
{
     struct User users[MAX_USERS];
     int numUsers = 0;
     char choice;

     // Load existing user data from file
     FILE *file = fopen("userdata.txt", "r");
     if (file != NULL)
     {
          while (fscanf(file, "%s %s", users[numUsers].username, users[numUsers].passwordHash) != EOF)
          {
               numUsers++;
          }
          fclose(file);
     }

     do
     {
          printf("\n\n\n");
          middtab1();
          printf("1. Sign Up\n");
          middtab1();
          printf("2. Login\n");
          middtab1();
          printf("3. Continue...\n");
          middtab1();
          printf("Enter your choice: ");
          scanf(" %c", &choice);

          switch (choice)
          {
          case '1':
               signUp(users, &numUsers);
               break;
          case '2':
               if (login(users, numUsers))
               {
                    br(1);
                    pre(4);
                    printf("Login successful!\n");
               }
               else
               {
                    printf("Login failed. Invalid username or password.\n");
               }
               break;
          case '3':

               break;
          default:
               printf("Invalid choice. Please try again.\n");
          }
     } while (choice != '3');

     // Save user data to file before exiting
     file = fopen("userdata.txt", "a");
     if (file != NULL)
     {
          for (int i = 0; i < numUsers; i++)
          {
               fprintf(file, "%s %s\n", users[i].username, users[i].passwordHash);
          }
          fclose(file);
     }
}

void signUp(struct User users[], int *numUsers)
{
     if (*numUsers >= MAX_USERS)
     {
          printf("Maximum number of users reached.\n");
          return;
     }

     char username[MAX_USERNAME_LENGTH];
     br(2);
     pre(4);
     printf("Enter username: ");
     scanf("%s", username);

     for (int i = 0; i < *numUsers; i++)
     {
          if (strcmp(users[i].username, username) == 0)
          {
               printf("Username already exists. Please choose a different username.\n");
               return;
          }
     }

     strcpy(users[*numUsers].username, username);

     char password[MAX_USERNAME_LENGTH];
     br(1);
     pre(4);
     printf("Enter password: ");

     int p = 0;
     do
     {
          password[p] = getch();
          if (password[p] != '\r')
          {
               printf("*");
          }
          p++;
     } while (password[p - 1] != '\r');
     password[p - 1] = '\0';

     hashPassword(password, users[*numUsers].passwordHash);

     (*numUsers)++;
     br(2);
     pre(4);
     printf("Enter your address: ");
     scanf("%s", address);
     address[strcspn(address, "\n")] = '\0';
     br(1);
     pre(4);
     printf("Enter your phone number: ");
     scanf("%s", phone);
     phone[strcspn(phone, "\n")] = '\0';
     br(1);
     pre(4);
     printf("Sign up successful!\n");
}

bool login(struct User users[], int numUsers)
{
     char username[MAX_USERNAME_LENGTH];
     br(1);
     pre(4);
     printf("Enter username: ");
     scanf("%s", username);

     // Check if username exists
     bool userExists = false;
     for (int i = 0; i < numUsers; i++)
     {
          if (strcmp(users[i].username, username) == 0)
          {
               userExists = true;
               break;
          }
     }

     if (!userExists)
     {
          br(1);
          pre(4);
          printf("User does not exist. Please sign up first.\n");
          return false;
     }

     char key[MAX_USERNAME_LENGTH];
     br(1);
     pre(4);
     printf("Enter password: ");
     // scanf("%s", password);

     int pa = 0;

     do
     {
          key[pa] = getch();
          if (key[pa] != '\r')
          {
               printf("*");
          }
          pa++;
     } while (key[pa - 1] != '\r');
     key[pa - 1] = '\0';

     char hash[HASH_LENGTH + 1];
     hashPassword(key, hash);

     for (int i = 0; i < numUsers; i++)
     {
          if (strcmp(users[i].username, username) == 0 && strcmp(users[i].passwordHash, hash) == 0)
          {
               return true;
          }
     }
     return false;
}

void hashPassword(const char *password, char *hash)
{
     SHA256_CTX ctx;
     sha256_init(&ctx);
     sha256_update(&ctx, (const uint8_t *)password, strlen(password));
     sha256_final(&ctx, (uint8_t *)hash);
     hash[HASH_LENGTH] = '\0'; // Null terminator
}

void Applycoupon()
{
     printf("Want a discount coupon? Click the link below.\n");
     pre(4);
     printf("\033]8;;https://sites.google.com/view/flavourdash/home \aLink to your Coupon\033]8;;\a\n");
}

void generate_invoice(char foodname[25], int quantity, float price, char username[50], char address[100], char phone[15])
{
     // cls();
     FILE *invoice;
     char filename[30];
     sprintf(filename, "Invoice.txt");
     invoice = fopen(filename, "a");

     if (invoice == NULL)
     {
          printf("Error creating invoice file!\n");
          return;
     }

     fprintf(invoice, "================== INVOICE ==================\n");
     fprintf(invoice, "Customer Name: %s\n", username);
     fprintf(invoice, "Address: %s\n", address);
     fprintf(invoice, "Phone: %s\n", phone);
     fprintf(invoice, "---------------------------------------------\n");
     fprintf(invoice, "Item Name       Quantity       Price\n");
     fprintf(invoice, "%-15s %-15d %-15.2f\n", foodname, quantity, price);
     fprintf(invoice, "---------------------------------------------\n");
     fprintf(invoice, "Total Amount: %.2f\n", price);
     fprintf(invoice, "=============================================\n");
     fprintf(invoice, "\n \n");
     fclose(invoice);

     printf("================== INVOICE ==================\n");
     pre(4);
     printf("Customer Name: %s\n", username);
     pre(4);
     printf("Address: %s\n", address);
     pre(4);
     printf("Phone: %s\n", phone);
     pre(4);
     printf("---------------------------------------------\n");
     pre(4);
     printf("Item Name       Quantity       Price\n");
     pre(4);
     printf("%-15s %-15d %-15.2f\n", foodname, quantity, price);
     pre(4);
     printf("---------------------------------------------\n");
     pre(4);
     printf("Total Amount: %.2f\n", price);
     pre(4);
     printf("=============================================\n");

     Sleep(4000);
}

void write_review(char foodname[25])
{
     cls();
     char review[300];
     FILE *file = fopen("reviews.txt", "a");

     if (file == NULL)
     {
          printf("Unable to open reviews file.\n");
          return;
     }
     br(5);
     pre(4);
     printf("Food item: %s", foodname);
     br(2);
     pre(4);
     printf("Please enter your review: ");
     fflush(stdin);
     br(2);
     pre(4);
     fgets(review, sizeof(review), stdin);
     review[strcspn(review, "\n")] = '\0';

     fprintf(file, "\n \n", review);
     fprintf(file, "Food Item: %s\n", foodname);
     fprintf(file, "%s\n", review);
     fclose(file);
     br(2);
     pre(4);
     printf("Thank you for your review!\n");
}

//  gcc file.c sha256.c -o file
// ./file

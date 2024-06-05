
 payment:

               fflush(stdin);
               scanf("%d", &payment);

               // cash
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

          pre(4);
          printf("Total money : %.2f \n\n", totalmoney);
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
          }
     }

     int ps_menu;
psmenu:

     fflush(stdin);
     scanf("%d", &ps_menu);

     if (ps_menu == 1)
     {
          goto foodlist;
     }
     else if (ps_menu == 2)
     {
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
                           // int has_coupon;
                           // printf("\n");
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
               printf("Enter Your Card No : ");

               fflush(stdin);
               scanf("%d", &card_number[c]);

               cardno[c] = card_number[c];

               br(2);
               pre(2);
               printf("Enter Your Card Pin   : ");

               fflush(stdin);
               // scanf("%d",&pin);
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
               // printf("\nYou have entered %s as pin",pin);
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
          }
     }
     else
     {
          int card_number[100];

          c++;

          cls();
          middle1();
          pre(4);
          printf("Enter Your Card No : ");

          fflush(stdin);
          scanf("%d", &card_number[c]);

          cardno[c] = card_number[c];

          br(2);
          pre(2);
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
          // printf("\nYou have entered %s as pin",pin);
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
     }

     int ps_menu2;
psmenu2:

     scanf("%d", &ps_menu2);

     if (ps_menu2 == 1)
     {
          goto foodlist;
     }
     else if (ps_menu2 == 2)
     {
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

               cls();
               middle1();
               pre(4);
               printf("Enter Your ID : ");

               fflush(stdin);
               scanf("%d", &iut_card[c]);

               cardno[c] = iut_card[c];

               br(2);
               pre(2);
               fflush(stdin);

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
          }
     }
     else
     {
          int iut_card[100];

          c++;

          cls();
          middle1();
          pre(4);
          printf("Enter Your ID : ");

          fflush(stdin);
          scanf("%d", &iut_card[c]);

          cardno[c] = iut_card[c];

          br(2);
          pre(2);
          fflush(stdin);

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
     }

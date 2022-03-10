#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NO_NEED 300
//뿌리지 않는 옵션은 300으로 설정

char *hotdog[4]={"","소세지 핫도그","치즈 핫도그","가래떡 핫도그"};
char *seasoning[5]={"","어니언 크림","버터 갈릭","설탕","시즈닝 필요없음"};
char *sauce[5]={"","머스터드","스위트 칠리","토마토 케챱","소스 필요없음"};

int hotdog_stock[4]={0,40,20,30};
int seasoning_stock[5]={0,50,50,50,NO_NEED};
int sauce_stock[5]={0,50,30,20,NO_NEED};

int hotdog_price[4]={0,2000,3000,2500};
int seasoning_price[5]={0,500,500,0,0};
int sauce_price[5]={0,200,350,150,0};

char answer=0;
//yes/no

void touch_screen();
//메뉴 선택 전 초기화면(터치 스크린)


int menu,op1,op2,total_price,payment,input_cash,change,total_sales=0;


int main()
{

    touch_screen();


    //메뉴: 핫도그 선택

    printf(" ┏━♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡━┓\n");
    printf(" ♡　　　　　　　　                                         ♡\n");
    printf("                    <<  H O T D O G  >>                       \n");
    printf("                                                              \n");
    printf(" ♥---------------------------------------------------------♥\n");
    printf("                                                              \n");
    printf(" ♥                      M E N U                            ♥\n");
    printf("                                                              \n");
    printf("                                                              \n");
    printf("               1.   소 세 지 핫 도 그 (%d원)                  \n",hotdog_price[1]);
    printf("                                                              \n");
    printf("               2.    치 즈 핫 도 그  (%d원)                   \n",hotdog_price[2]);
    printf("                                                              \n");
    printf("               3.   가 래 떡 핫 도 그 (%d원)                  \n",hotdog_price[3]);
    printf("                                                              \n");
    printf(" ┗━♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡━┛\n");


    printf(" ♥---------------------------------------------------------♥\n");

    for(;;)
    {

      printf("               메뉴를 선택해 주세요 : ");
      scanf("%d", &menu);


      if(menu<1 || menu>3)
      {
         printf(" ------------------------------------------------------------ \n");
         printf("    1~3번 메뉴 중에서 선택해 주세요\n");
         printf(" ------------------------------------------------------------ \n");
         continue;
      }

      else if(menu>=1 && menu<=3)
      {


         if(hotdog_stock[menu]<=0)
         {
            printf(" ------------------------------------------------------------ \n");
            printf("재고 부족! 다른 메뉴를 선택해주세요.\n");
            printf(" ------------------------------------------------------------ \n");
            continue;
         }


         break;
      }


    }





    //옵션 1: 시즈닝 선택

    for(;;)

    {

        printf(" ------------------------------------------------------------\n");
        printf("  Option 1 :   1. 어니언 크림 (%d원)    2. 버터 갈릭 (%d원)  \n",seasoning_price[1],seasoning_price[2]);
        printf("               3. 설탕 (%d원)             4. 시즈닝 필요없음 \n",seasoning_price[3]);

      printf(" ------------------------------------------------------------\n");
      printf("             시즈닝을 선택해 주세요 : ");
        scanf("%d",&op1);


      if(op1<1 || op1>4)
      {
         printf(" ------------------------------------------------------------\n");
         printf("1~4번 옵션 중에서 선택해 주세요\n");
         continue;
      }

      else if(op1>=1 && op1<=4)
      {


         if(seasoning_stock[op1]<=0)
         {
            printf(" ------------------------------------------------------------ \n");
            printf("재고 부족! 다른 옵션을 선택해주세요.\n");
            continue;
         }


         break;
      }


    }




    //옵션 2: 소스 선택


    for(;;)
    {
        printf(" ------------------------------------------------------------\n");
        printf("  Option 2 :   1. 머스터드 (%d원)       2. 스위트 칠리 (%d원)\n",sauce_price[1],sauce_price[2]);
        printf("               3. 토마토 케챱 (%d원)    4. 소스 필요없음     \n",sauce_price[3]);


      printf(" ------------------------------------------------------------\n");
      printf("               소스를 선택해 주세요 : ");
        scanf("%d",&op2);


      if(op2<1 || op2>4)
      {
         printf(" ------------------------------------------------------------\n");
         printf("    1~4번 옵션 중에서 선택해 주세요\n");
         continue;
      }

      else if(op2>=1 && op2<=4)
      {


         if(sauce_stock[op2]<=0)
         {
            printf(" ------------------------------------------------------------\n");
            printf("재고 부족! 다른 옵션을 선택해주세요.\n");
            continue;
         }


         break;
      }


    }




    //주문서 발행

    total_price=hotdog_price[menu]+seasoning_price[op1]+sauce_price[op2];

    for(;;)
    {
        printf(" ------------------------------------------------------------\n");
        printf("                                                             \n");
        printf("  주문서 : %s (옵션 1: %3s 옵션 2: %3s)                      \n",hotdog[menu],seasoning[op1],sauce[op2]);
        printf("                                                             \n");
        printf("  결제 금액 : %d원                                         \n",total_price);
        printf("                                                             \n");
        printf(" ------------------------------------------------------------\n");

        printf("               주문 하시겠습니까? (Y/N) : "); getchar();

        scanf("%c",&answer);


            if(answer=='Y' || answer=='y')
            {
                break;
            }

            else if(answer=='N'|| answer=='n')
            {
                printf(" ------------------------------------------------------------ \n");
                printf("    주문을 취소합니다. 처음 화면으로 돌아갑니다\n");
                getchar();
                getchar();
                system("cls");
                touch_screen();
                break;
            }
            else
            {
                printf(" ------------------------------------------------------------ \n");
                printf("          ★★★잘못된 입력값입니다.\n");
                getchar();
                getchar();
                continue;
            }

    }



        printf(" ------------------------------------------------------------ \n");




        //결제 수단 선택

        int flag=0;

        while(flag==0)
        {
            printf("     결제수단을 선택하세요 -> 신용카드(0) / 현금(1) : ");
            scanf("%d",&payment);

            printf(" ------------------------------------------------------------ \n");

            switch(payment)
            {

                //카드 결제

                case 0:



                    printf("                                               \n");
                    printf("     카드를 넣어주세요.                        \n"); getchar(); getchar();
                    printf("     카드 승인중");  Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                    printf("\n     결제가 완료되었습니다. 카드를 제거해주세요.\n");
                    getchar();


                    hotdog_stock[menu]--;
                    seasoning_stock[op1]--;
                    sauce_stock[op2]--;

                    total_sales+=total_price;
                    total_price=0;

                    printf(" ------------------------------------------------------------ \n");
                    printf("    핫도그가 구워지고 있어요! 잠시만 기다려 주세요");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                    printf("\n    시즈닝을 뿌리는 중입니다 ");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("♥"); Sleep(500);
                    printf("\n    소스를 뿌리는 중입니다 ");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("♥\n");Sleep(500);
                    printf(" ------------------------------------------------------------ \n");
                    printf("   주문하신 %s(%s/%s)가 나왔습니다!\n",hotdog[menu],seasoning[op1],sauce[op2]);
                    printf("   맛있게 드세요^^");
                    printf("                                                              \n");

                    flag=1;
                    getchar();
                    Sleep(150);
                    touch_screen();
                    break;


                //현금 결제

                case 1:

                    for(;;)
                    {

                        printf("    현금을 투입구에 넣고 투입한 금액을 입력해주세요 : ");
                        scanf("%d",&input_cash);
                        printf(" ------------------------------------------------------------ \n");
                        getchar();

                        if(input_cash<total_price)
                        {


                            printf("    금액이 부족합니다 계속 진행하시겠어요?(Y/N) :");
                            scanf("%c",&answer);

                            if(answer=='Y'|| answer=='y')
                            {
                                printf(" ------------------------------------------------------------ \n");
                                continue;
                            }

                            else if(answer=='N'|| answer=='n')
                            {
                                printf(" ------------------------------------------------------------ \n");
                                printf("    결제가 취소되었습니다 반환된 현금을 가져가세요.\n");
                                system("cls");
                                touch_screen();
                                break;
                            }
                            else
                            {
                                printf(" ------------------------------------------------------------ \n");
                                printf("          ★★★잘못된 입력값입니다.\n");
                                getchar();
                                getchar();
                                continue;
                            }


                        }



                        else if(input_cash==total_price)
                        {

                            printf("    결제가 완료되었습니다");
                            break;
                        }




                        else
                        {
                            printf("    결제가 완료되었습니다. "); Sleep(200);

                            change=abs(total_price-input_cash);

                            printf("거스름돈 %d원을 가져가세요",change); getchar();

                            break;
                        }



                    }



                        hotdog_stock[menu]--;
                        seasoning_stock[op1]--;
                        sauce_stock[op2]--;
                        total_sales+=total_price;
                        total_price=0;


                        printf(" ------------------------------------------------------------ \n");
                        printf("    핫도그가 구워지고 있어요! 잠시만 기다려 주세요");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                        printf("\n    시즈닝을 뿌리는 중입니다 ");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("♥"); Sleep(500);
                        printf("\n    소스를 뿌리는 중입니다 ");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("♥\n");Sleep(500);
                        printf(" ------------------------------------------------------------ \n");
                        printf("   주문하신 %s(%s/%s)가 나왔습니다!\n",hotdog[menu],seasoning[op1],sauce[op2]);
                        printf("   맛있게 드세요^^");
                        printf("                                                       \n");

                        flag=1;
                        getchar();
                        Sleep(150);
                        touch_screen();
                        break;

                default:
                    printf("       ★★★다른 결제 수단은 지원되지 않습니다.\n");
                    printf(" ------------------------------------------------------------ \n");
                    continue;
            }


        }





    return 0;
}





void touch_screen()
{

    printf("====☆====================================☆====\n");
    printf("                                                \n");
    printf("     어서오세요!  무인 핫도그 자판기입니다      \n");
    printf("                                                \n");
    printf("       화면을 터치하여 메뉴를 확인하세요!       \n");
    printf("                                                \n");
    printf("===========☆======================☆===========\n");
    printf("------------------------------------------------\n");

    getchar();  //화면터치=enter 입력
    Sleep(200);
    system("cls");

    return ;

}


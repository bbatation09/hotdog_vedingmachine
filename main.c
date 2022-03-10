#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NO_NEED 300
//�Ѹ��� �ʴ� �ɼ��� 300���� ����

char *hotdog[4]={"","�Ҽ��� �ֵ���","ġ�� �ֵ���","������ �ֵ���"};
char *seasoning[5]={"","��Ͼ� ũ��","���� ����","����","����� �ʿ����"};
char *sauce[5]={"","�ӽ��͵�","����Ʈ ĥ��","�丶�� �ɪy","�ҽ� �ʿ����"};

int hotdog_stock[4]={0,40,20,30};
int seasoning_stock[5]={0,50,50,50,NO_NEED};
int sauce_stock[5]={0,50,30,20,NO_NEED};

int hotdog_price[4]={0,2000,3000,2500};
int seasoning_price[5]={0,500,500,0,0};
int sauce_price[5]={0,200,350,150,0};

char answer=0;
//yes/no

void touch_screen();
//�޴� ���� �� �ʱ�ȭ��(��ġ ��ũ��)


int menu,op1,op2,total_price,payment,input_cash,change,total_sales=0;


int main()
{

    touch_screen();


    //�޴�: �ֵ��� ����

    printf(" ������������������������������������������������������������������������������������������������������������������\n");
    printf(" ������������������                                         ��\n");
    printf("                    <<  H O T D O G  >>                       \n");
    printf("                                                              \n");
    printf(" ��---------------------------------------------------------��\n");
    printf("                                                              \n");
    printf(" ��                      M E N U                            ��\n");
    printf("                                                              \n");
    printf("                                                              \n");
    printf("               1.   �� �� �� �� �� �� (%d��)                  \n",hotdog_price[1]);
    printf("                                                              \n");
    printf("               2.    ġ �� �� �� ��  (%d��)                   \n",hotdog_price[2]);
    printf("                                                              \n");
    printf("               3.   �� �� �� �� �� �� (%d��)                  \n",hotdog_price[3]);
    printf("                                                              \n");
    printf(" ������������������������������������������������������������������������������������������������������������������\n");


    printf(" ��---------------------------------------------------------��\n");

    for(;;)
    {

      printf("               �޴��� ������ �ּ��� : ");
      scanf("%d", &menu);


      if(menu<1 || menu>3)
      {
         printf(" ------------------------------------------------------------ \n");
         printf("    1~3�� �޴� �߿��� ������ �ּ���\n");
         printf(" ------------------------------------------------------------ \n");
         continue;
      }

      else if(menu>=1 && menu<=3)
      {


         if(hotdog_stock[menu]<=0)
         {
            printf(" ------------------------------------------------------------ \n");
            printf("��� ����! �ٸ� �޴��� �������ּ���.\n");
            printf(" ------------------------------------------------------------ \n");
            continue;
         }


         break;
      }


    }





    //�ɼ� 1: ����� ����

    for(;;)

    {

        printf(" ------------------------------------------------------------\n");
        printf("  Option 1 :   1. ��Ͼ� ũ�� (%d��)    2. ���� ���� (%d��)  \n",seasoning_price[1],seasoning_price[2]);
        printf("               3. ���� (%d��)             4. ����� �ʿ���� \n",seasoning_price[3]);

      printf(" ------------------------------------------------------------\n");
      printf("             ������� ������ �ּ��� : ");
        scanf("%d",&op1);


      if(op1<1 || op1>4)
      {
         printf(" ------------------------------------------------------------\n");
         printf("1~4�� �ɼ� �߿��� ������ �ּ���\n");
         continue;
      }

      else if(op1>=1 && op1<=4)
      {


         if(seasoning_stock[op1]<=0)
         {
            printf(" ------------------------------------------------------------ \n");
            printf("��� ����! �ٸ� �ɼ��� �������ּ���.\n");
            continue;
         }


         break;
      }


    }




    //�ɼ� 2: �ҽ� ����


    for(;;)
    {
        printf(" ------------------------------------------------------------\n");
        printf("  Option 2 :   1. �ӽ��͵� (%d��)       2. ����Ʈ ĥ�� (%d��)\n",sauce_price[1],sauce_price[2]);
        printf("               3. �丶�� �ɪy (%d��)    4. �ҽ� �ʿ����     \n",sauce_price[3]);


      printf(" ------------------------------------------------------------\n");
      printf("               �ҽ��� ������ �ּ��� : ");
        scanf("%d",&op2);


      if(op2<1 || op2>4)
      {
         printf(" ------------------------------------------------------------\n");
         printf("    1~4�� �ɼ� �߿��� ������ �ּ���\n");
         continue;
      }

      else if(op2>=1 && op2<=4)
      {


         if(sauce_stock[op2]<=0)
         {
            printf(" ------------------------------------------------------------\n");
            printf("��� ����! �ٸ� �ɼ��� �������ּ���.\n");
            continue;
         }


         break;
      }


    }




    //�ֹ��� ����

    total_price=hotdog_price[menu]+seasoning_price[op1]+sauce_price[op2];

    for(;;)
    {
        printf(" ------------------------------------------------------------\n");
        printf("                                                             \n");
        printf("  �ֹ��� : %s (�ɼ� 1: %3s �ɼ� 2: %3s)                      \n",hotdog[menu],seasoning[op1],sauce[op2]);
        printf("                                                             \n");
        printf("  ���� �ݾ� : %d��                                         \n",total_price);
        printf("                                                             \n");
        printf(" ------------------------------------------------------------\n");

        printf("               �ֹ� �Ͻðڽ��ϱ�? (Y/N) : "); getchar();

        scanf("%c",&answer);


            if(answer=='Y' || answer=='y')
            {
                break;
            }

            else if(answer=='N'|| answer=='n')
            {
                printf(" ------------------------------------------------------------ \n");
                printf("    �ֹ��� ����մϴ�. ó�� ȭ������ ���ư��ϴ�\n");
                getchar();
                getchar();
                system("cls");
                touch_screen();
                break;
            }
            else
            {
                printf(" ------------------------------------------------------------ \n");
                printf("          �ڡڡ��߸��� �Է°��Դϴ�.\n");
                getchar();
                getchar();
                continue;
            }

    }



        printf(" ------------------------------------------------------------ \n");




        //���� ���� ����

        int flag=0;

        while(flag==0)
        {
            printf("     ���������� �����ϼ��� -> �ſ�ī��(0) / ����(1) : ");
            scanf("%d",&payment);

            printf(" ------------------------------------------------------------ \n");

            switch(payment)
            {

                //ī�� ����

                case 0:



                    printf("                                               \n");
                    printf("     ī�带 �־��ּ���.                        \n"); getchar(); getchar();
                    printf("     ī�� ������");  Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                    printf("\n     ������ �Ϸ�Ǿ����ϴ�. ī�带 �������ּ���.\n");
                    getchar();


                    hotdog_stock[menu]--;
                    seasoning_stock[op1]--;
                    sauce_stock[op2]--;

                    total_sales+=total_price;
                    total_price=0;

                    printf(" ------------------------------------------------------------ \n");
                    printf("    �ֵ��װ� �������� �־��! ��ø� ��ٷ� �ּ���");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                    printf("\n    ������� �Ѹ��� ���Դϴ� ");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("��"); Sleep(500);
                    printf("\n    �ҽ��� �Ѹ��� ���Դϴ� ");
                    Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("��\n");Sleep(500);
                    printf(" ------------------------------------------------------------ \n");
                    printf("   �ֹ��Ͻ� %s(%s/%s)�� ���Խ��ϴ�!\n",hotdog[menu],seasoning[op1],sauce[op2]);
                    printf("   ���ְ� �弼��^^");
                    printf("                                                              \n");

                    flag=1;
                    getchar();
                    Sleep(150);
                    touch_screen();
                    break;


                //���� ����

                case 1:

                    for(;;)
                    {

                        printf("    ������ ���Ա��� �ְ� ������ �ݾ��� �Է����ּ��� : ");
                        scanf("%d",&input_cash);
                        printf(" ------------------------------------------------------------ \n");
                        getchar();

                        if(input_cash<total_price)
                        {


                            printf("    �ݾ��� �����մϴ� ��� �����Ͻðھ��?(Y/N) :");
                            scanf("%c",&answer);

                            if(answer=='Y'|| answer=='y')
                            {
                                printf(" ------------------------------------------------------------ \n");
                                continue;
                            }

                            else if(answer=='N'|| answer=='n')
                            {
                                printf(" ------------------------------------------------------------ \n");
                                printf("    ������ ��ҵǾ����ϴ� ��ȯ�� ������ ����������.\n");
                                system("cls");
                                touch_screen();
                                break;
                            }
                            else
                            {
                                printf(" ------------------------------------------------------------ \n");
                                printf("          �ڡڡ��߸��� �Է°��Դϴ�.\n");
                                getchar();
                                getchar();
                                continue;
                            }


                        }



                        else if(input_cash==total_price)
                        {

                            printf("    ������ �Ϸ�Ǿ����ϴ�");
                            break;
                        }




                        else
                        {
                            printf("    ������ �Ϸ�Ǿ����ϴ�. "); Sleep(200);

                            change=abs(total_price-input_cash);

                            printf("�Ž����� %d���� ����������",change); getchar();

                            break;
                        }



                    }



                        hotdog_stock[menu]--;
                        seasoning_stock[op1]--;
                        sauce_stock[op2]--;
                        total_sales+=total_price;
                        total_price=0;


                        printf(" ------------------------------------------------------------ \n");
                        printf("    �ֵ��װ� �������� �־��! ��ø� ��ٷ� �ּ���");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500);
                        printf("\n    ������� �Ѹ��� ���Դϴ� ");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("��"); Sleep(500);
                        printf("\n    �ҽ��� �Ѹ��� ���Դϴ� ");
                        Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); printf("��\n");Sleep(500);
                        printf(" ------------------------------------------------------------ \n");
                        printf("   �ֹ��Ͻ� %s(%s/%s)�� ���Խ��ϴ�!\n",hotdog[menu],seasoning[op1],sauce[op2]);
                        printf("   ���ְ� �弼��^^");
                        printf("                                                       \n");

                        flag=1;
                        getchar();
                        Sleep(150);
                        touch_screen();
                        break;

                default:
                    printf("       �ڡڡڴٸ� ���� ������ �������� �ʽ��ϴ�.\n");
                    printf(" ------------------------------------------------------------ \n");
                    continue;
            }


        }





    return 0;
}





void touch_screen()
{

    printf("====��====================================��====\n");
    printf("                                                \n");
    printf("     �������!  ���� �ֵ��� ���Ǳ��Դϴ�      \n");
    printf("                                                \n");
    printf("       ȭ���� ��ġ�Ͽ� �޴��� Ȯ���ϼ���!       \n");
    printf("                                                \n");
    printf("===========��======================��===========\n");
    printf("------------------------------------------------\n");

    getchar();  //ȭ����ġ=enter �Է�
    Sleep(200);
    system("cls");

    return ;

}


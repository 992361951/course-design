#include "main.h"

int main()
{
    system("color 1F");
   login();    //login();//�˺�Ϊ001 ����Ϊ123

    dormitory* head = readDataIntoList("date.txt");//���ļ�
   
        for (;;) {
            switch (menu())
            {
            case 0:
                exit(1);
                break;
            case 1:
                printList(head);
                break;
            case 2:
                print_spareroom(head);
                break;
            case 3:
                mergeSort(&head);
                printlist_plus(head);//���ڿ�ͷͻ�����෿����
                break;
            case 4:
                create_add_node(&head);
                printList(head);
                break;
            case 5:
                changge(&head);
                break;
            case 6:
                delete_node(&head);
                break;
            case 7:
                search(head);//���壬������head
                break;
            case 8:
                count(head);//���壬������head
                break;
            case 9:
                backup(&head);
                break;
            default:
                printf("�������˴��������");
                break;
            }
        }
}


 



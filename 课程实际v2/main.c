#include "main.h"

int main()
{
    system("color 1F");
   login();    //login();//账号为001 密码为123

    dormitory* head = readDataIntoList("date.txt");//读文件
   
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
                printlist_plus(head);//会在开头突出空余房间数
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
                search(head);//看清，这里是head
                break;
            case 8:
                count(head);//看清，这里是head
                break;
            case 9:
                backup(&head);
                break;
            default:
                printf("您输入了错误的数据");
                break;
            }
        }
}


 



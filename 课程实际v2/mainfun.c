#include "main.h"

//#define _CRT_SECURE_NO_WARNINGS
void login()
{
    char userName[5];
    char password[5];

    FILE* fp = fopen("password.txt", "r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ��");
        return;
    }
    fscanf(fp, "%s", password);
    fclose(fp);
    fp == NULL;

    printf("%s", password);

    char inputpass[10];
    int i;
    printf("\n\n   ---------------------------------��ӭʹ��---------------------------------\n");
    for (i = 1; i < 4; i++)
    {
        printf("\n       �����������û���:");
        gets(userName);
        printf("\n       ��������������:");
        gets(inputpass);
        if ((strcmp(userName, "001") == 0) && (strcmp(password, inputpass) == 0))
            /*��֤�û���������*/
        {

           
            system("cls");
            printf("\n\n   ---------------------------��½�ɹ�----------------------------------\n\n");
           
            printf("\t\t   ��1�޸�����    ��2����ʹ��\n\t\t\t\t");
            int choice;
            scanf("%d", &choice);

            do {
                if (choice == 1)
                {
                    change_pass();
                }
                if (choice == 2)
                {
                    system("cls");
                    return;
                }

            } while (choice != 1 && choice != 2);
            

            
        }
        else
        {
            if (i < 3)
            {
                printf("\n     �û����������������������!\n");
            }
            else
            {
                printf("\n     ��������3�ν��û������������ϵͳ���˳�!");
                exit(0);
            }
        }
    }
}

void change_pass()
{
   
    while (1)
    {
        printf("��������ԭ�ȵ�����");
        char password[10];
        scanf("%s", password);

        printf("���ٴ�ȷ������");
        char password2[10];
        scanf("%s", password2);

        if ((strcmp(password, password2) == 0))
        {   
            FILE* fp = fopen("password.txt", "w");
            if (fp == NULL)
            {
                printf("���ļ�ʧ��");
                return;
            }

            char newpassword[10];
            printf("������������");
            char password[10];
            scanf("%s", newpassword);

            fprintf(fp, "%s\n", newpassword);
            fclose(fp);
            fp = NULL;
            printf("��������ɹ��������µ�¼");
            exit(1);
        }
        else
        {
            printf("��������������벻һ��,����������");
        }
    }
}

void write_filetolist(dormitory**  head) //д�ļ�
{

    dormitory* current = *head;
    

    FILE* fp = fopen("date.txt", "w");
    if (fp == NULL)
    {
        printf("���ļ�ʧ��");
        return;
    }
    while (current!=NULL)
    {
        fprintf(fp, "%s %s %d %d %d %s\n", current->id, current->gender, current->allroom,
            current->dividedroom, current->spareroom, current->faculty);
        current = current->next;
    };
    fclose(fp);
}


//void read_filetolist(link* plist)//���ļ�
//{
//    FILE* file = fopen("text.txt", "r");
//    if (file == NULL) {
//        printf("�޷����ļ�\n");
//        return ;
//    }
//
//    
//    
//    while (fscanf(file, "%99[^\n]%*c", newnode) == 1) {
//        append(&head, line);
//    }
//
//    fclose(file)
//}

//�ں����ڲ�������һ������������malloc�����ģ�ֻ�践��ͷ����
dormitory* readDataIntoList(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ�\n");
        return NULL;
    }

    dormitory* head = NULL;
    dormitory* tail = NULL;
    dormitory* newDorm;

    while (!feof(file)) {
        newDorm = (dormitory*)malloc(sizeof(dormitory));
        if (fscanf(file, "%s %s %d %d %d %s", newDorm->id, newDorm->gender, &newDorm->allroom, &newDorm->dividedroom, &newDorm->spareroom, &newDorm->faculty) == 6) {
            newDorm->next = NULL;
            if (head == NULL) {
                head = newDorm;
                tail = newDorm;
            }
            else {
                tail->next = newDorm;
                tail = newDorm;
            }
        }
        else {
            free(newDorm);
        }
    }

    fclose(file);
    return head;
}//

//��ӡ������ͷ������
void printList(dormitory* list) {//��ͷ����ȥ���Ϳɴ�ӡ������
    system("cls");
    while (list != NULL) {
        printf("ID: %s\t", list->id);
        printf("Gender: %s\t", list->gender);
        printf("All Room: %d\t", list->allroom);
        printf("Divided Room: %d \t", list->dividedroom);
        printf("Spare Room: %d\t", list->spareroom);
        printf("Faculty: %s\t", list->faculty);
        printf("\n");
        list = list->next;
    }
   
    system("pause");
    system("cls");
}

void printlist_plus(dormitory* list) //���ڿ�ͷͻ�����෿��
{
    
    system("cls");
    while (list != NULL) {
        printf("���෿��Ϊ: %d\t", list->spareroom);

        printf("ID: %s\t", list->id);
        printf("Gender: %s\t", list->gender);
        printf("All Room: %d\t", list->allroom);
        printf("Divided Room: %d \t", list->dividedroom);
        printf("Spare Room: %d\t", list->spareroom);
        printf("Faculty: %s\t", list->faculty);
        printf("\n");
        list = list->next;
    }

    system("pause");
    system("cls");
}

void print_spareroom(dormitory* head)
{
    dormitory* current = head;
    int i = 1;
    while (current != NULL)
    {
        if (current->spareroom != 0)
        {
            printf("��%d����������\t", i);
            printf("ID: %s\t", current->id);
            printf("Gender: %s\t", current->gender);
            printf("All Room: %d\t", current->allroom);
            printf("Divided Room: %d \t", current->dividedroom);
            printf("Spare Room: %d\t", current->spareroom);
            printf("Faculty: %s\t", current->faculty);
            printf("\n");
            i++;
        }
        current = current->next;
        
    }
   
    system("pause");
    system("cls");
}

///////////////////////////////////////�鲢����//////////////////////////////////////////////////
dormitory* merge(dormitory* left, dormitory* right) {
    dormitory dummy;
    dormitory* tail = &dummy;
    dummy.next = NULL;

    while (left && right) {
        if (left->spareroom >= right->spareroom) {
            tail->next = left;
            left = left->next;
        }
        else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left) {
        tail->next = left;
    }
    else {
        tail->next = right;
    }

    return dummy.next;
}

// �鲢����ʹ�÷������������ͷ����ȥ
void mergeSort(dormitory** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }

    dormitory* current = *head_ref;
    dormitory* left, * right;

    // Ѱ�������м�ڵ�
    dormitory* mid = current;
    dormitory* fast = current->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            mid = mid->next;
            fast = fast->next;
        }
    }

    left = *head_ref;
    right = mid->next;
    mid->next = NULL;

    mergeSort(&left);
    mergeSort(&right);

    *head_ref = merge(left, right);
}   
/////////////////////////////////////////�鲢����/////////////////////////////////////////////////////
// 
// 
// ��ӽڵ㵽����ĩβ
void appendNode(dormitory** head_ref, dormitory* new_node) {
    dormitory* current = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}



void create_add_node(dormitory** head)
{
    dormitory* newnode = (dormitory*)malloc(sizeof(dormitory));
    if (newnode == NULL) {
        printf("�ڴ����ʧ��\n");
        return;
    }

    //Ϊ�½ڵ㸳ֵ
    newnode->next = NULL;
  
    printf("������id  �磺dong-1-312�� xi-3-548 :");
    scanf("%s", newnode->id);
    printf("�������Ա�ʵ����--������������ᣬ����male�������Ů�����ᣬ����female     :");
    scanf("%s", newnode->gender);
    printf("������һ�����ٴ�λ:");
    scanf("%d", &newnode->allroom);
    printf("�������ѷ���Ĵ�λ:");
    scanf("%d", &newnode->dividedroom);
    printf("������Ժϵ����       ����Ǽ�����ģ����룺jxj  ������Զ����ģ�����zdh    :");
    scanf("%s", &newnode->faculty);
    /////////////////////////////////////////////////////////////////////////////////////////////
    newnode->spareroom = newnode->allroom - newnode->dividedroom;
    
    //attend
    appendNode(head, newnode);
    
    write_filetolist(head);

    printf("��ӳɹ���������Ҫ�鿴�����������Ϣ�����Ҫ���밴1�������Ҫ�˳�����0  ��");
    int choice;
    scanf("%d", &choice);
    do {
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            printList(*head);
        }
        else {
            printf("�������˴��������");
        }
    } while (choice != 0 && choice != 1);
}


int menu()
{
    int choice;

    //�������ǲ˵�����

    do {
        printf("\n\n----------------------ѧ���������ϵͳ----------------------\n\n");
        printf("��� 1. ��ʾ�����������Ϣ                              ���\n\n");
        printf("��� 2. ��ʾ�п��ലλ�Ĺ�Ԣ��Ϣ                        ���\n\n");
        printf("��� 3. �����ലλ���жൽ��������ʾ                  ���\n\n");
        //��ɾ��
        printf("��� 4. ���ӷ���                                        ���\n\n");
        printf("��� 5. �޸ķ����д�λ����Ϣ                            ���\n\n");
        printf("��� 6. ɾ������                                        ���\n\n");
        //����
        printf("��� 7. ��ѯ                                             ���\n\n");
     // printf("��� 8. ����������ѯ:��ѯѧԺŮ�����������Ĵ�λ���      ���\n\n");
        //����
        printf("��� 8. ͳ��ĳѧԺ���ലλ���                           ���\n\n");
        printf("��� 9. ����                                             ���\n\n");
        printf("��� 0. �˳�ϵͳ                                         ���\n\n");
        printf("-----------------------------------------------------------------\n");
        printf("��ѡ����Ҫ���е�ѡ�(0-9):  ");
        scanf("%d", &choice);


    } while (choice < 0 || choice>9);
    printf("\n");
    printf("\n");
    return choice;

}

void delete_node(dormitory** head)
{
    printf("��������Ҫɾ���������ID:(�磺dong-1-312���м��ú��߸�����) ");
    char key[20];
    scanf("%s", key);

    dormitory* current = *head;
    dormitory* pre=NULL;
    if (current == NULL)
    {
        printf("��������ϵͳ��û��һ������");
        return;
    }

    if (strcmp(current->id, key) == 0) {
        *head = current->next; // Ҫɾ������ͷ�ڵ�
        free(current); // �ͷ�ɾ���ڵ���ڴ�
        write_filetolist(head);
        printf("ɾ���ɹ�\n");
        return;
    }

    while (current != NULL&& strcmp(current->id, key) != 0)
    {
        pre = current;
        current = current->next;
        
    }

    pre->next = current->next;
    write_filetolist(head);
  
    printf("ɾ���ɹ�");
    system("pause");
}
 
void changge(dormitory** head)
{
    system("cls");
    printf("��������Ҫ���ĵ��������Ϣ��ID:    �磺dong-1-312���м��ú��߸���)\n");
    char key[10];
    scanf("%s", key);
    dormitory* current = *head;
    
    if (current == NULL)
    {
        printf("��������ϵͳ��û��һ������\n");
    }
    while (current != NULL && strcmp(current->id, key) != 0)
    {
        current = current->next;
    }
    printf("������ԭ������ϢΪ:\n");
    printonenode(current);

    printf("������ĺ��������ס����");
    int changes;//���ĺ��������ס����
    scanf("%d", &changes);
   
    printf("���ĳɹ�\n");

    current->dividedroom = changes;
    current->spareroom = (current->allroom) - (current->dividedroom);

    printonenode(current);

    write_filetolist(head);
}

void printonenode(dormitory* current) {  //ֱ�Ӵ�ӡһ���ڵ����Ϣ
    printf("ID: %s\n", current->id);
    printf("Gender: %s\n", current->gender);
    printf("All Room: %d\n", current->allroom);
    printf("Divided Room: %d\n", current->dividedroom);//
    printf("Spare Room: %d\n", current->spareroom);//
    printf("Faculty: %s\t", current->faculty);
    printf("\n\n");
}

void backup(dormitory** head) //����
{

    dormitory* current = *head;


    FILE* fp = fopen("backup.txt", "w");
    if (fp == NULL)
    {
        printf("���ļ�ʧ��");
        return;
    }
    while (current != NULL)
    {
        fprintf(fp, "%s %s %d %d %d %s\n", current->id, current->gender, current->allroom,
            current->dividedroom, current->spareroom, current->faculty);
        current = current->next;
    };
    fclose(fp);
    system("cls");
    printf("");
    printf("���ݳɹ�,����ѡ������һ���Ĳ���,�������ݱ�����backup.txt \n");
    system("pause");
    system("cls");
}

void count(dormitory* head)
{
    system("cls");
    printf("����1��ͳ�Ƽ����ѧԺ�Ŀ��ലλ\n����2��ͳ���Զ���ѧԺ�Ŀ��ലλ\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        count_ji(head);
    }
    else if (choice == 2) 
    {
        count_zi(head);
    }
    else {
        printf("�������˴��������");
    }
    system("pause");
    system("cls");
}
void count_ji(dormitory* head)
{
    dormitory* current = head;
    printf("�����ѧԺ�п��ലλ�������У�\n\n");
    int sum=0;
    while (current)
    {   if((strcmp(current->faculty,"jsj"))==0)
        {
            printonenode(current);
            sum += (current->spareroom);
        }
  

        current = current->next;
    }
    printf("\n     �����ѧԺ�ܹ����෿����Ϊ��%d    ", sum);
}
void count_zi(dormitory* head)
{
    dormitory* current = head;
    int sum = 0;
    printf("�Զ���ѧԺ�п��ലλ��\n");
    while (current)
        {
            if ((strcmp(current->faculty, "zdh")) == 0)
            {
                printonenode(current);
                sum += (current->spareroom);
        }
            
            current = current->next;
        }
    printf("\n     �Զ���ѧԺ�ܹ����෿����Ϊ��%d    ", sum);
}

void search(dormitory* head)
{
    system("cls");
    printf("��1����һ������ѯ\n");
    int choice;
    printf("��2������������ѯ\n");
    scanf("%d", &choice);

    if (choice == 1)
        search_singal(head);
    else if (choice == 2)
       mulsearch( head );
    else {
        printf("�������˴��������");
    }
}
void search_singal(dormitory* head)
{
    printf("��1��ͨ������id��ѯ��֧��ģ����ѯ��\n");

    printf("��2����ѯ������Ů������\n");

    printf("��3����ѯԺϵ��֧��ģ����ѯ��\n");

    dormitory* current = head;
    
    int choice;
    char key[20];
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("������id(֧��ģ����ѯ)    �磺dong-1-312���м��ú��߸�����\n");
       
        scanf("%s", key);

        while (current != NULL) {
            if (strstr(current->id, key) != NULL) {
                printonenode(current);
            }
            current = current->next;
        }
        break;
    case 2:
        printf("��ѡ���ѯ�������ỹ��Ů������\n���Ҫ��ѯ�������ᣬ����male�����Ҫ��ѯŮ�����ᣬ����female\n");
        
        scanf("%s", key);

        while (current)
        {
            if ((strcpy(current->faculty, key)) != 0) 
            {
                printonenode(current);
            }
            current = current->next;
        }
        break;
    case 3:
        printf("������Ժϵ    ���������ʱ������jxj  �����Զ���ʱ������zdh�������ֲ�Ҫ���ִ��֣�\n");
        
        scanf("%s", key);

        while (current != NULL) {
            if (strstr(current->faculty, key) != NULL)
            {
                printonenode(current);
            }
            current = current->next;
        }
        break;

    default:

        printf("�������˴��������,������\n");
        return;
    }

    system("pause");
}

void mulsearch(dormitory* head)
{
    dormitory* current = head;

    printf("������Ժϵ  (���������ʱ������jxj  �����Զ���ʱ������zdh)\n");
    char faculty[10];
    scanf("%s", faculty);
    printf("\n");

    printf("�����Ҫ��ѯ���������������᣺������male \n�����Ů�����᣺������female\n");
    char gender[10];
    scanf("%s", gender);
    system("cls");

    /*printf("����������¥:(�������������1����5�����ᣬ������ dong-1 (���س�)  dong-5)\n");
    char eastorwest;
    
    printf("�����������ѯ����¥����ʼλ�ã����磺����������1����1������1���ɣ�");*/
    system("cls");

    printf("��Ѱ���Ϊ��\n");
        while (current!=NULL)
        {
            if ((strcpy(current->faculty, faculty)) != NULL && (strcpy(current->gender, gender)) != NULL)
            {
                printonenode(current);
            }
            current = current->next;
        }
        system("pause");
        system("cls");
}
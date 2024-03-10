#include "main.h"

//#define _CRT_SECURE_NO_WARNINGS
void login()
{
    char userName[5];
    char password[5];

    FILE* fp = fopen("password.txt", "r");
    if (fp == NULL)
    {
        printf("打开文件失败");
        return;
    }
    fscanf(fp, "%s", password);
    fclose(fp);
    fp == NULL;

    printf("%s", password);

    char inputpass[10];
    int i;
    printf("\n\n   ---------------------------------欢迎使用---------------------------------\n");
    for (i = 1; i < 4; i++)
    {
        printf("\n       请输入您的用户名:");
        gets(userName);
        printf("\n       请输入您的密码:");
        gets(inputpass);
        if ((strcmp(userName, "001") == 0) && (strcmp(password, inputpass) == 0))
            /*验证用户名和密码*/
        {

           
            system("cls");
            printf("\n\n   ---------------------------登陆成功----------------------------------\n\n");
           
            printf("\t\t   按1修改密码    按2继续使用\n\t\t\t\t");
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
                printf("\n     用户名或密码错误，请重新输入!\n");
            }
            else
            {
                printf("\n     您已连续3次将用户名或密码输错，系统将退出!");
                exit(0);
            }
        }
    }
}

void change_pass()
{
   
    while (1)
    {
        printf("请输入您原先的密码");
        char password[10];
        scanf("%s", password);

        printf("请再次确认密码");
        char password2[10];
        scanf("%s", password2);

        if ((strcmp(password, password2) == 0))
        {   
            FILE* fp = fopen("password.txt", "w");
            if (fp == NULL)
            {
                printf("打开文件失败");
                return;
            }

            char newpassword[10];
            printf("请输入新密码");
            char password[10];
            scanf("%s", newpassword);

            fprintf(fp, "%s\n", newpassword);
            fclose(fp);
            fp = NULL;
            printf("更改密码成功，请重新登录");
            exit(1);
        }
        else
        {
            printf("您两次输入的密码不一致,请重新输入");
        }
    }
}

void write_filetolist(dormitory**  head) //写文件
{

    dormitory* current = *head;
    

    FILE* fp = fopen("date.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件失败");
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


//void read_filetolist(link* plist)//读文件
//{
//    FILE* file = fopen("text.txt", "r");
//    if (file == NULL) {
//        printf("无法打开文件\n");
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

//在函数内部创建了一个链表，由于是malloc出来的，只需返回头就行
dormitory* readDataIntoList(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件\n");
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

//打印链表里头的数据
void printList(dormitory* list) {//将头传进去，就可打印出链表
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

void printlist_plus(dormitory* list) //会在开头突出空余房间
{
    
    system("cls");
    while (list != NULL) {
        printf("空余房间为: %d\t", list->spareroom);

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
            printf("第%d个空余宿舍\t", i);
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

///////////////////////////////////////归并排序//////////////////////////////////////////////////
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

// 归并排序，使用方法：将链表的头传进去
void mergeSort(dormitory** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }

    dormitory* current = *head_ref;
    dormitory* left, * right;

    // 寻找链表中间节点
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
/////////////////////////////////////////归并排序/////////////////////////////////////////////////////
// 
// 
// 添加节点到链表末尾
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
        printf("内存分配失败\n");
        return;
    }

    //为新节点赋值
    newnode->next = NULL;
  
    printf("请输入id  如：dong-1-312或 xi-3-548 :");
    scanf("%s", newnode->id);
    printf("请输入性别（实例）--如果是男生宿舍，输入male，如果是女生宿舍，输入female     :");
    scanf("%s", newnode->gender);
    printf("请输入一共多少床位:");
    scanf("%d", &newnode->allroom);
    printf("请输入已分配的床位:");
    scanf("%d", &newnode->dividedroom);
    printf("请输入院系名称       如果是计算机的，输入：jxj  如果是自动化的，输入zdh    :");
    scanf("%s", &newnode->faculty);
    /////////////////////////////////////////////////////////////////////////////////////////////
    newnode->spareroom = newnode->allroom - newnode->dividedroom;
    
    //attend
    appendNode(head, newnode);
    
    write_filetolist(head);

    printf("添加成功，请问您要查看所有宿舍的信息吗？如果要，请按1，如果想要退出，按0  ：");
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
            printf("您输入了错误的数字");
        }
    } while (choice != 0 && choice != 1);
}


int menu()
{
    int choice;

    //接下来是菜单界面

    do {
        printf("\n\n----------------------学生宿舍管理系统----------------------\n\n");
        printf("☆☆ 1. 显示所有宿舍的信息                              ☆☆\n\n");
        printf("☆☆ 2. 显示有空余床位的公寓信息                        ☆☆\n\n");
        printf("☆☆ 3. 按空余床位数有多到少排序并显示                  ☆☆\n\n");
        //增删改
        printf("☆☆ 4. 增加房间                                        ☆☆\n\n");
        printf("☆☆ 5. 修改房间中床位的信息                            ☆☆\n\n");
        printf("☆☆ 6. 删除房间                                        ☆☆\n\n");
        //查找
        printf("☆☆ 7. 查询                                             ☆☆\n\n");
     // printf("☆☆ 8. 多重条件查询:查询学院女生（男生）的床位情况      ☆☆\n\n");
        //其他
        printf("☆☆ 8. 统计某学院空余床位情况                           ☆☆\n\n");
        printf("☆☆ 9. 备份                                             ☆☆\n\n");
        printf("☆☆ 0. 退出系统                                         ☆☆\n\n");
        printf("-----------------------------------------------------------------\n");
        printf("请选择您要运行的选项按(0-9):  ");
        scanf("%d", &choice);


    } while (choice < 0 || choice>9);
    printf("\n");
    printf("\n");
    return choice;

}

void delete_node(dormitory** head)
{
    printf("请输入您要删除的宿舍的ID:(如：dong-1-312（中间用横线隔开）) ");
    char key[20];
    scanf("%s", key);

    dormitory* current = *head;
    dormitory* pre=NULL;
    if (current == NULL)
    {
        printf("整个宿舍系统里没有一个房间");
        return;
    }

    if (strcmp(current->id, key) == 0) {
        *head = current->next; // 要删除的是头节点
        free(current); // 释放删除节点的内存
        write_filetolist(head);
        printf("删除成功\n");
        return;
    }

    while (current != NULL&& strcmp(current->id, key) != 0)
    {
        pre = current;
        current = current->next;
        
    }

    pre->next = current->next;
    write_filetolist(head);
  
    printf("删除成功");
    system("pause");
}
 
void changge(dormitory** head)
{
    system("cls");
    printf("请输入您要更改的宿舍的信息的ID:    如：dong-1-312（中间用横线隔开)\n");
    char key[10];
    scanf("%s", key);
    dormitory* current = *head;
    
    if (current == NULL)
    {
        printf("整个宿舍系统里没有一个房间\n");
    }
    while (current != NULL && strcmp(current->id, key) != 0)
    {
        current = current->next;
    }
    printf("该宿舍原本的信息为:\n");
    printonenode(current);

    printf("输入更改后宿舍的入住人数");
    int changes;//更改后宿舍的入住人数
    scanf("%d", &changes);
   
    printf("更改成功\n");

    current->dividedroom = changes;
    current->spareroom = (current->allroom) - (current->dividedroom);

    printonenode(current);

    write_filetolist(head);
}

void printonenode(dormitory* current) {  //直接打印一个节点的信息
    printf("ID: %s\n", current->id);
    printf("Gender: %s\n", current->gender);
    printf("All Room: %d\n", current->allroom);
    printf("Divided Room: %d\n", current->dividedroom);//
    printf("Spare Room: %d\n", current->spareroom);//
    printf("Faculty: %s\t", current->faculty);
    printf("\n\n");
}

void backup(dormitory** head) //备份
{

    dormitory* current = *head;


    FILE* fp = fopen("backup.txt", "w");
    if (fp == NULL)
    {
        printf("打开文件失败");
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
    printf("备份成功,请您选择您下一步的操作,备份数据保存在backup.txt \n");
    system("pause");
    system("cls");
}

void count(dormitory* head)
{
    system("cls");
    printf("输入1，统计计算机学院的空余床位\n输入2，统计自动化学院的空余床位\n");
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
        printf("您输入了错误的数字");
    }
    system("pause");
    system("cls");
}
void count_ji(dormitory* head)
{
    dormitory* current = head;
    printf("计算机学院有空余床位的宿舍有：\n\n");
    int sum=0;
    while (current)
    {   if((strcmp(current->faculty,"jsj"))==0)
        {
            printonenode(current);
            sum += (current->spareroom);
        }
  

        current = current->next;
    }
    printf("\n     计算机学院总共空余房间数为：%d    ", sum);
}
void count_zi(dormitory* head)
{
    dormitory* current = head;
    int sum = 0;
    printf("自动化学院有空余床位：\n");
    while (current)
        {
            if ((strcmp(current->faculty, "zdh")) == 0)
            {
                printonenode(current);
                sum += (current->spareroom);
        }
            
            current = current->next;
        }
    printf("\n     自动化学院总共空余房间数为：%d    ", sum);
}

void search(dormitory* head)
{
    system("cls");
    printf("按1：单一条件查询\n");
    int choice;
    printf("按2：多重条件查询\n");
    scanf("%d", &choice);

    if (choice == 1)
        search_singal(head);
    else if (choice == 2)
       mulsearch( head );
    else {
        printf("您输入了错误的数据");
    }
}
void search_singal(dormitory* head)
{
    printf("按1：通过宿舍id查询（支持模糊查询）\n");

    printf("按2：查询男生或女生宿舍\n");

    printf("按3：查询院系（支持模糊查询）\n");

    dormitory* current = head;
    
    int choice;
    char key[20];
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("请输入id(支持模糊查询)    如：dong-1-312（中间用横线隔开）\n");
       
        scanf("%s", key);

        while (current != NULL) {
            if (strstr(current->id, key) != NULL) {
                printonenode(current);
            }
            current = current->next;
        }
        break;
    case 2:
        printf("请选择查询男生宿舍还是女生宿舍\n如果要查询男生宿舍，输入male，如果要查询女生宿舍，输入female\n");
        
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
        printf("请输入院系    搜索计算机时：输入jxj  搜索自动化时：输入zdh（可少字不要多字错字）\n");
        
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

        printf("您输入了错误的数据,请重试\n");
        return;
    }

    system("pause");
}

void mulsearch(dormitory* head)
{
    dormitory* current = head;

    printf("请输入院系  (搜索计算机时：输入jxj  搜索自动化时：输入zdh)\n");
    char faculty[10];
    scanf("%s", faculty);
    printf("\n");

    printf("如果您要查询的宿舍是男生宿舍：请输入male \n如果是女生宿舍：请输入female\n");
    char gender[10];
    scanf("%s", gender);
    system("cls");

    /*printf("请输入宿舍楼:(如果你想搜索东1到东5的宿舍，请输入 dong-1 (按回车)  dong-5)\n");
    char eastorwest;
    
    printf("请输入您想查询宿舍楼的起始位置；（如：您想搜索东1或西1，均按1即可）");*/
    system("cls");

    printf("搜寻结果为：\n");
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
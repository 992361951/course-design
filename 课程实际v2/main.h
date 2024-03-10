#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct dormitory
{
	char id[20];
	char gender[20];
	int allroom;
	int dividedroom;
	int spareroom;
	int faculty[20];
	struct dormitory* next;
}dormitory;

//typedef struct link
//{
//	dormitory* head;
//}link;
//以下是函数声明
void login();// 登录函数，验证用户身份

void change_pass();// 修改密码函数

dormitory* readDataIntoList(const char* filename);// 从文件中读取数据并存储到链表中

void printList(dormitory* list);// 打印链表中的数据

void printlist_plus(dormitory* list);// 打印链表中的数据，并突出显示空余房间数

//以下是排序用到的函数//////////////////////////////////////////////////////////////////////////
dormitory* merge(dormitory* left, dormitory* right);

void mergeSort(dormitory** head_ref);// 使用归并排序按照空余房间数量对链表进行排序

void appendNode(dormitory** head_ref, dormitory* new_node);// 添加新的宿舍数据到链表中
/////////////////////////////////////////////////////////////////////////////////////////////////over

void create_add_node(dormitory** head);// 添加新的宿舍数据到链表中

void write_filetolist(dormitory** head);// 将链表中的数据写入文件

void print_spareroom(dormitory* head);// 打印有空余房间的宿舍信息

int menu();// 显示菜单并返回用户选择

void delete_node(dormitory** head);// 删除链表中的节点

void changge(dormitory** head);// 修改链表中节点的信息

void printonenode(dormitory* current);// 打印单个节点的信息

void count(dormitory* head);// 统计特定学院的空余床位数量

void count_ji(dormitory* head);// 统计计算机学院的空余床位数量

void count_zi(dormitory* head);// 统计自动化学院的空余床位数量	

void search_singal(dormitory* head);// 单条件查询宿舍信息

void mulsearch(dormitory* head);// 多条件查询宿舍信息

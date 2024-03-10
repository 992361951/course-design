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
//�����Ǻ�������
void login();// ��¼��������֤�û����

void change_pass();// �޸����뺯��

dormitory* readDataIntoList(const char* filename);// ���ļ��ж�ȡ���ݲ��洢��������

void printList(dormitory* list);// ��ӡ�����е�����

void printlist_plus(dormitory* list);// ��ӡ�����е����ݣ���ͻ����ʾ���෿����

//�����������õ��ĺ���//////////////////////////////////////////////////////////////////////////
dormitory* merge(dormitory* left, dormitory* right);

void mergeSort(dormitory** head_ref);// ʹ�ù鲢�����տ��෿�������������������

void appendNode(dormitory** head_ref, dormitory* new_node);// ����µ��������ݵ�������
/////////////////////////////////////////////////////////////////////////////////////////////////over

void create_add_node(dormitory** head);// ����µ��������ݵ�������

void write_filetolist(dormitory** head);// �������е�����д���ļ�

void print_spareroom(dormitory* head);// ��ӡ�п��෿���������Ϣ

int menu();// ��ʾ�˵��������û�ѡ��

void delete_node(dormitory** head);// ɾ�������еĽڵ�

void changge(dormitory** head);// �޸������нڵ����Ϣ

void printonenode(dormitory* current);// ��ӡ�����ڵ����Ϣ

void count(dormitory* head);// ͳ���ض�ѧԺ�Ŀ��ലλ����

void count_ji(dormitory* head);// ͳ�Ƽ����ѧԺ�Ŀ��ലλ����

void count_zi(dormitory* head);// ͳ���Զ���ѧԺ�Ŀ��ലλ����	

void search_singal(dormitory* head);// ��������ѯ������Ϣ

void mulsearch(dormitory* head);// ��������ѯ������Ϣ

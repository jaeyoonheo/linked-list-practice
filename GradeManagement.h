#pragma once
#include <stdio.h>   //����� 
#include <stdlib.h>	 //�����Ҵ� ��
#include <string.h>  //���ڿ� �������


typedef struct grade
{
	int Stn; //�й�
	char name[10]; //�л��̸�
	int num; //����

	grade *next;
}grade;

grade *head;
grade *eg;
int cnt = 0;
float hap = 0;


void add(int Sn);

void print(grade *head);

void del(int Sn);

void search(int Sn);

void sort(grade *head);

void exit(grade *head);
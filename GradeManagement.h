#pragma once
#include <stdio.h>   //입출력 
#include <stdlib.h>	 //동적할당 등
#include <string.h>  //문자열 헤더파일


typedef struct grade
{
	int Stn; //학번
	char name[10]; //학생이름
	int num; //점수

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
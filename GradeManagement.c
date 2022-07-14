#include "myheader.h"

void add(int Sn)
{
	eg = head->next;


	if (eg != NULL)
	{
		while (eg->Stn != Sn)
		{
			eg = eg->next;
			if (eg == '\0')
			{
				grade *add = (grade*)malloc(sizeof(grade)); //새로운 노드를 동적 할당

				add->Stn = Sn; //add->Stn에 Sn을 대입

				printf("학생 이름을 입력해주세요 : ");
				scanf("%s", add->name);
				printf("점수를 입력해주세요 : ");
				scanf("%d", &add->num);

				add->next = head->next;
				head->next = add; //head뒤에 add를 연결

				cnt = cnt + 1;
				hap = hap + add->num;
				return;
			}

		}
		printf("이미 입력된 값입니다.\n");
		return;
	}


	grade *add = (grade*)malloc(sizeof(grade)); //새로운 노드를 동적 할당

	add->Stn = Sn; //add->Stn에 Sn을 대입

	printf("학생 이름을 입력해주세요 : ");
	scanf("%s", add->name);
	printf("점수를 입력해주세요 : ");
	scanf("%d", &add->num);

	add->next = head->next;
	head->next = add; //head뒤에 add를 연결

	cnt = cnt + 1;
	hap = hap + add->num;
}

void print(grade *head)
{
	eg = head->next;

	if (eg == NULL)
	{
		printf("입력된 값을 찾을 수 없습니다. \n");
		return;
	}
	while (eg != NULL)
	{
		printf("학번 : %d \n", eg->Stn);
		printf("이름 : %s \n", eg->name);
		printf("점수 : %d \n\n", eg->num);
		eg = eg->next;
	}
}

void del(int Sn)
{
	eg = head;
	if (head->next == NULL)
	{
		printf("입력된 값을 찾을 수 없습니다.\n");
		return;
	}

	else
	{
		while (head != NULL)
		{
			if (head->next == '\0')
			{
				printf("입력된 값을 찾을 수 없습니다.\n");
				head = eg;
				return;
			}
			else if (head->next->Stn == Sn)
			{
				cnt = cnt - 1;
				hap = hap - head->next->num;

				grade *temp = head->next;
				head->next = head->next->next;

				free(temp);
				head = eg;

				return;
			}
			head = head->next;
		}

	}
}

void search(int Sn)
{
	eg = head->next;
	if (eg == NULL)
	{
		printf("입력된 값을 찾을 수 없습니다.\n");
		return;
	}

	else
	{
		while (eg->Stn != Sn)
		{
			eg = eg->next;
			if (eg == '\0')
			{
				printf("입력된 값을 찾을 수 없습니다.\n");
				return;
			}

		}

		printf("학번 : %d \n", eg->Stn);
		printf("이름 : %s \n", eg->name);
		printf("점수 : %d \n", eg->num);
	}
}

void sort(grade *head)     //버블소트 사용
{
	grade *p = head;
	grade *r;

	for (p = head; p->next != NULL; p = p->next)
	{
		for (r = head; r->next->next != NULL; r = r->next)
		{
			if (r->next->Stn > r->next->next->Stn)
			{
				grade *t1 = r->next;
				grade *t2 = r->next->next;

				r->next = t2;
				t1->next = r->next->next;
				t2->next = t1;
			}
		}
	}
}

void exit(grade *head)
{
	if (head == NULL);
	else {
		exit(head->next);
		free(head);
	}
}
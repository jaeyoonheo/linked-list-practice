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
				grade *add = (grade*)malloc(sizeof(grade)); //���ο� ��带 ���� �Ҵ�

				add->Stn = Sn; //add->Stn�� Sn�� ����

				printf("�л� �̸��� �Է����ּ��� : ");
				scanf("%s", add->name);
				printf("������ �Է����ּ��� : ");
				scanf("%d", &add->num);

				add->next = head->next;
				head->next = add; //head�ڿ� add�� ����

				cnt = cnt + 1;
				hap = hap + add->num;
				return;
			}

		}
		printf("�̹� �Էµ� ���Դϴ�.\n");
		return;
	}


	grade *add = (grade*)malloc(sizeof(grade)); //���ο� ��带 ���� �Ҵ�

	add->Stn = Sn; //add->Stn�� Sn�� ����

	printf("�л� �̸��� �Է����ּ��� : ");
	scanf("%s", add->name);
	printf("������ �Է����ּ��� : ");
	scanf("%d", &add->num);

	add->next = head->next;
	head->next = add; //head�ڿ� add�� ����

	cnt = cnt + 1;
	hap = hap + add->num;
}

void print(grade *head)
{
	eg = head->next;

	if (eg == NULL)
	{
		printf("�Էµ� ���� ã�� �� �����ϴ�. \n");
		return;
	}
	while (eg != NULL)
	{
		printf("�й� : %d \n", eg->Stn);
		printf("�̸� : %s \n", eg->name);
		printf("���� : %d \n\n", eg->num);
		eg = eg->next;
	}
}

void del(int Sn)
{
	eg = head;
	if (head->next == NULL)
	{
		printf("�Էµ� ���� ã�� �� �����ϴ�.\n");
		return;
	}

	else
	{
		while (head != NULL)
		{
			if (head->next == '\0')
			{
				printf("�Էµ� ���� ã�� �� �����ϴ�.\n");
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
		printf("�Էµ� ���� ã�� �� �����ϴ�.\n");
		return;
	}

	else
	{
		while (eg->Stn != Sn)
		{
			eg = eg->next;
			if (eg == '\0')
			{
				printf("�Էµ� ���� ã�� �� �����ϴ�.\n");
				return;
			}

		}

		printf("�й� : %d \n", eg->Stn);
		printf("�̸� : %s \n", eg->name);
		printf("���� : %d \n", eg->num);
	}
}

void sort(grade *head)     //�����Ʈ ���
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
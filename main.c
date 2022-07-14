#include <stdio.h>   //����� 
#include <stdlib.h>	 //�����Ҵ� ��

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

void add(int Sn)
{
	eg = head->next;
	
	//�˻��� ���� ������� �а� �̹� �Էµ� �й��� �Էµȴٸ� öȸ
	if(eg!=NULL)
	{
		while (eg->Stn != Sn)
		{
			eg = eg->next;
			if (eg == NULL)
			{
				grade *add = (grade*)malloc(sizeof(grade)); //���ο� ��带 ���� �Ҵ�

				add->Stn = Sn; //add->Stn�� Sn�� ����

				printf("�л� �̸��� �Է����ּ��� : ");
				scanf_s("%s", add->name,10);
				printf("������ �Է����ּ��� : ");
				scanf_s("%d", &add->num);

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
	scanf_s("%s", add->name,10);
	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &add->num);

	add->next = head->next;
	head->next = add; //head�ڿ� add�� ����

	cnt = cnt + 1;
	hap = hap + add->num;
}

void print(grade *head)
{
	eg = head->next;

	if (eg == NULL)  //����� ����ü�� ������
	{
		printf("�Էµ� ���� ã�� �� �����ϴ�. \n");
		return;
	}
	while (eg != NULL)  //����� ����ü�� �������� Ż��
	{
		printf("�й� : %d \n", eg->Stn);
		printf("�̸� : %s \n", eg->name);
		printf("���� : %d \n\n", eg->num);
		eg = eg->next;
	}
}

void del(int Sn)
{
	//search�� ���� ������� ������ ��ȣ�� �˻�


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
			if (head->next == NULL)
			{
				printf("�Էµ� ���� ã�� �� �����ϴ�.\n");
				head = eg;
				return;
			}
			else if (head->next->Stn == Sn)
			{
				cnt = cnt - 1;
				hap = hap - head->next->num;

				grade *temp = head->next;			//head->next�� ����
				head->next = head->next->next;		//head�� head�Ǵ������� �κ��� ����

				free(temp);
				head = eg;							//head�� �ٽ� �Ǿ�����
			
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
		while (eg->Stn != Sn)		//�Է��� �й��� �ش� ����ü�� �ѹ��� ��ġ�ϸ� ���
		{
			eg = eg->next;
			if (eg == NULL)
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
	grade *p=head;
	grade *r;

	for (p = head; p->next != NULL; p = p->next)
	{
		for (r = head; r->next->next != NULL; r = r->next)
		{
			if (r->next->Stn > r->next->next->Stn)
			{
				grade *t1 = r->next;				//�ٲܴ��1
				grade *t2 = r->next->next;		//�ٲܴ��2

				r->next = t2;					//1�� 3�� ����
				t1->next = r->next->next;		//2�� 4�� ����
				t2->next = t1;					//3�� 2�� ����
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

int main()
{
	int pn = 0;
	int Sn = 0;

	head = (grade*)malloc(sizeof(grade));		//head�� ���� �Ҵ�
	head->next = NULL;							//head�� next�� ó������ NULL�� ����Ŵ

	

	while (1)
	{
		printf("[1]��� [2]�˻� [3]�Է� [4]���� [5]���� [6]����\n");
	
		printf("��ȣ�� �Է����ּ��� : ");

		scanf_s("%d", &pn);

		switch (pn)
		{
			case 1:
			{
				print(head);
				printf("----------------------------------------\n");
				break;
			}
			case 2:
			{
				printf("�й��� �Է����ּ���. : ");
				scanf_s("%d", &Sn);
				search(Sn);
				printf("----------------------------------------\n");
				break;
			}
			case 3:
			{
				printf("�й��� �Է����ּ���. : ");
				scanf_s("%d", &Sn);
				add(Sn);
				printf("----------------------------------------\n");
				break;
			}
			case 4:
			{
				printf("�й��� �Է����ּ���. : ");
				scanf_s("%d", &Sn);
				del(Sn);
				printf("----------------------------------------\n");
				break;
			}
			case 5:
			{
				sort(head);
				printf("----------------------------------------\n");
				break;
			}
			case 6:
			{
				exit(head);
				return 0;
			}
			default:
			{
				printf("�߸� �Է��ϼ̽��ϴ�.");
				break;
			}
		}
		if(hap!=0)
			printf("�Է��� ���� : %d  ��� ���� : %3.1f\n", cnt, hap/cnt);
	}
}

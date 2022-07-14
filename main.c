#include <stdio.h>   //입출력 
#include <stdlib.h>	 //동적할당 등

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

void add(int Sn)
{
	eg = head->next;
	
	//검색과 같은 방식으로 읽고 이미 입력된 학번이 입력된다면 철회
	if(eg!=NULL)
	{
		while (eg->Stn != Sn)
		{
			eg = eg->next;
			if (eg == NULL)
			{
				grade *add = (grade*)malloc(sizeof(grade)); //새로운 노드를 동적 할당

				add->Stn = Sn; //add->Stn에 Sn을 대입

				printf("학생 이름을 입력해주세요 : ");
				scanf_s("%s", add->name,10);
				printf("점수를 입력해주세요 : ");
				scanf_s("%d", &add->num);

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
	scanf_s("%s", add->name,10);
	printf("점수를 입력해주세요 : ");
	scanf_s("%d", &add->num);

	add->next = head->next;
	head->next = add; //head뒤에 add를 연결

	cnt = cnt + 1;
	hap = hap + add->num;
}

void print(grade *head)
{
	eg = head->next;

	if (eg == NULL)  //연결된 구조체가 없으면
	{
		printf("입력된 값을 찾을 수 없습니다. \n");
		return;
	}
	while (eg != NULL)  //출력할 구조체가 없어지면 탈출
	{
		printf("학번 : %d \n", eg->Stn);
		printf("이름 : %s \n", eg->name);
		printf("점수 : %d \n\n", eg->num);
		eg = eg->next;
	}
}

void del(int Sn)
{
	//search와 같은 방식으로 삭제할 번호를 검색


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
			if (head->next == NULL)
			{
				printf("입력된 값을 찾을 수 없습니다.\n");
				head = eg;
				return;
			}
			else if (head->next->Stn == Sn)
			{
				cnt = cnt - 1;
				hap = hap - head->next->num;

				grade *temp = head->next;			//head->next를 저장
				head->next = head->next->next;		//head와 head의다음다음 부분을 연결

				free(temp);
				head = eg;							//head를 다시 맨앞으로
			
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
		while (eg->Stn != Sn)		//입력한 학번과 해당 구조체의 넘버가 일치하면 출력
		{
			eg = eg->next;
			if (eg == NULL)
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
	grade *p=head;
	grade *r;

	for (p = head; p->next != NULL; p = p->next)
	{
		for (r = head; r->next->next != NULL; r = r->next)
		{
			if (r->next->Stn > r->next->next->Stn)
			{
				grade *t1 = r->next;				//바꿀대상1
				grade *t2 = r->next->next;		//바꿀대상2

				r->next = t2;					//1과 3을 연결
				t1->next = r->next->next;		//2와 4를 연결
				t2->next = t1;					//3과 2를 연결
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

	head = (grade*)malloc(sizeof(grade));		//head를 동적 할당
	head->next = NULL;							//head의 next가 처음에는 NULL을 가리킴

	

	while (1)
	{
		printf("[1]출력 [2]검색 [3]입력 [4]삭제 [5]정렬 [6]종료\n");
	
		printf("번호를 입력해주세요 : ");

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
				printf("학번을 입력해주세요. : ");
				scanf_s("%d", &Sn);
				search(Sn);
				printf("----------------------------------------\n");
				break;
			}
			case 3:
			{
				printf("학번을 입력해주세요. : ");
				scanf_s("%d", &Sn);
				add(Sn);
				printf("----------------------------------------\n");
				break;
			}
			case 4:
			{
				printf("학번을 입력해주세요. : ");
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
				printf("잘못 입력하셨습니다.");
				break;
			}
		}
		if(hap!=0)
			printf("입력한 갯수 : %d  평균 점수 : %3.1f\n", cnt, hap/cnt);
	}
}

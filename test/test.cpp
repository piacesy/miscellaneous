#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 30 
#define COL 30 
#define P 0.5
#define PER_DO_TIMES 200
#define SOLU_DIM 243
#define POP_SIZE 200
#define CL_TIMES 100
#define P_CROSS 0.7
#define P_MUT 0.005
#define GEN_NUM 1000
int move(int x,int y,int dire);
/**������������α�����**/
double rand_zo()
{
	return (double)rand()/(double)(RAND_MAX);
}

/**��ʼ���ޱȵ����磬�Ը��ʣ������������з�������**/
void init_world(int world[][COL],double p)
{
	int i,j;
	//��ʼÿ������Ϊ�գ��ã���ʾ
	for(i = 0;i < ROW;i++)
	{
		for(j = 0;j < COL;j++)
		{
			world[i][j] = 0;
		}
	}

	//����ǽ��,2����ǽ��
	for(i = 0;i < ROW;i++)
	{
		world[0][i] = 2;
		world[i][0] = 2;
		world[ROW-1][i] = 2;
		world[i][COL-1] = 2;
	}

	//��������
	for(i = 1;i < ROW - 1;i++)
	{
		for(j = 1;j < COL - 1;j++)
		{
			if(rand_zo()<p)
				world[i][j] = 1;
		}
	}
}

/**��ӡ�ޱȵ�����**/
void print_world(int m[][COL])
{	
	int i,j;
	for(i = 0;i < ROW;i++)
	{
		for(j = 0;j < COL;j++)
			printf("%4d",m[i][j]);
		printf("\n");
	}
}

/**�����ޱȵ�ǰ����������ض�Ӧ�Ĳ��Ա��**/
int get_stra(int m[])
{
	//Լ����m�������Ԫ�ص����飬�ֱ��ʾ���������ϣ������У������Ԫ�ؿ���Ϊ0,1,2,�ֱ��ʾ�գ��й��ӣ�ǽ��
	int i,num = 0;
	for(i = 0;i < 5;i++)
	{
		num += m[i]*(pow(3,4 - i));
	}
	return num;
}

/**���ݲ��Ա�ST,ִ����ɨ����,���ض�Ӧ�ķ���**/
double do_clean(int wor[][COL],int ST[])
{
	//Լ��������ִ�еĶ����У�
	//				���ƶ�����
	//				���ƶ�����
	//				�����ƶ�����
	//				�����ƶ�����
	//				����ƶ�����
	//				������������
	//				������ӡ���
	//�Ʒֹ���
	//	����ޱ����ڵĸ������й��ӣ����Ҵ�ɨ�˹��ӣ�+10��
	//	���ִ�д�ɨ�Ķ�������ǰ������û�й���, -1��
	//	���ײ����ǽ��-5�֣����ҵ���ԭ���ĸ���
	
	//�����Ͻǿ�ʼ��ɨ
	int pos[2] = {1,1};
	double sc = 0;
	int i; 
	
	for(i = 0; i < PER_DO_TIMES;i++)
	{
		// �õ���ǰλ�õ����
		int situ[5];
		situ[0] = wor[pos[0] - 1][pos[1]];
		situ[1] = wor[pos[0]][pos[1] + 1];
		situ[2] = wor[pos[0] + 1][pos[1]];
		situ[3] = wor[pos[0]][pos[1] - 1];
		situ[4] = wor[pos[0]][pos[1]];
		// �õ�������µĲ��Ա��
		int str_num = get_stra(situ);
		// ���մ˲��Խ����ж�������wor��sc���ж�Ӧ����

		int dire;
		int rand_num;
		switch(ST[str_num])
		{
			case 0:
				//���ƶ�
N:
				if(move(pos[0],pos[1],0))
					sc -= 5;
				else
					pos[0]--;
				break;
			case 1:
				//���ƶ�
E:
				if(move(pos[0],pos[1],1))
					sc -= 5;
				else
					pos[1]++;
				break;
			case 2:
				//�����ƶ�
S:
				if(move(pos[0],pos[1],2))
					sc -= 5;
				else
					pos[0]++;
				break;
			case 3:
				//�����ƶ�
W:
				if(move(pos[0],pos[1],3))
					sc -= 5;
				else
					pos[1]--;
				break;
			case 4:
				//����ƶ�
				rand_num = rand_zo();
				if(rand_num < 0.25)
					goto N;
				else if(rand_num < 0.50)
					goto E;
				else if(rand_num < 0.75)
					goto S;
				else
					goto W;
				break;
			case 5:
				//����
				break;
			case 6:
				//�������
				if(wor[pos[0]][pos[1]] == 1)
					sc += 10;
				else
					sc -= 1;
				break;
		}
	}
	return sc;
}

//�ޱ��ƶ�,�����Ƿ�ײǽ(1��ʾײǽ),����ƶ�ʱ�����ƶ�����
int move(int x,int y,int dire)
{
	//Լ��:
	//		dire == 0,��
	//		dire == 1,��
	//		dire == 2,����
	//		dire == 3,����
	//		dire == 4,����ƶ�
	
	int rand_num;
	switch(dire)
	{
		case 0:
			if(--x == 0)
				return 1;
		case 1:
			if(++y == (COL - 1))
				return 1;
		case 2:
			if(++x == (ROW - 1))
				return 1;
		case 3:
			if(--y == 0)
				return 1;
	}
	return 0;	
}


/**��������������ȡ��**/
int m_round(double x)
{
	return (int)(x + 0.5);
}

/**���ɳ�ʼ��**/
void init_solu(int solu[][SOLU_DIM])
{
	int i,j;
	for(i = 0;i < POP_SIZE;i++)
		for(j = 0;j < SOLU_DIM;j++)
			solu[i][j] = m_round(rand_zo()*6);
}

/**��Ӧ��**/
void get_fitness(int solu[][SOLU_DIM],double fitness[])
{
	int i,j;
	
	int ST[SOLU_DIM]; //ÿ�������Ӧһ�Ų��Ա�

	for(i = 0; i < POP_SIZE;i++)
	{
		for(j = 0;j < SOLU_DIM;j++)
			ST[j] = solu[i][j];
		
		double per_sum = 0;
		/*����ÿһ�����壬����CL_TIMES�����ɨ,ȡƽ���ɼ���Ϊ������Ӧ�ȷ���,ÿһ�ε����綼��ͬ�����ǲ��Ա���ͬ*/
		for(j = 0;j < CL_TIMES;j++)
		{
			int wor[ROW][COL];
			init_world(wor,P);
			per_sum += do_clean(wor,ST);
		}

		//��֤��Ӧ��������
		fitness[i] = per_sum/CL_TIMES + 5*PER_DO_TIMES;		
	}

}

//ѡ������
void ga_sel(int old_pop[][SOLU_DIM])
{
	int new_pop[POP_SIZE][SOLU_DIM];
	double pr[POP_SIZE],cum_pr[POP_SIZE];
	get_fitness(old_pop,pr);

	double pr_sum = 0;
	int i,j,k;
	for(i = 0;i < POP_SIZE;i++)
		pr_sum += pr[i];

	for(i = 0;i < POP_SIZE;i++)
		pr[i] = pr[i]/pr_sum;

	cum_pr[0] = pr[0];

	for(i = 1;i < POP_SIZE;i++)
		cum_pr[i] = cum_pr[i - 1] + pr[i];

	//���̶ķ���ѡ��
	for(i = 0;i < POP_SIZE;i++)
	{
		double rand_n = rand_zo();
		for(j = 0; j < POP_SIZE - 1;j++)
		{
			if(rand_n < cum_pr[0])
			{
				for(k = 0;k < SOLU_DIM;k++)
					new_pop[i][k] = old_pop[0][k];
				break;
			}else if(rand_n >= cum_pr[j] && rand_n <= cum_pr[j+1])
			{
				for(k = 0;k < SOLU_DIM;k++)
					new_pop[i][k] = old_pop[j+1][k];
				break;
			}
		}
	}

	for(i = 0;i < POP_SIZE;i++)
		for(j = 0;j < SOLU_DIM;j++)
			old_pop[i][j] = new_pop[i][j];
}

//����
void ga_cross(int new_pop[][SOLU_DIM])
{
	//ѡ����Ҫ����ĸ���
	int count = 0;
	int need_cr[POP_SIZE];
	int i,j;

	for(i = 0;i < POP_SIZE;i++)
	{
		if(rand_zo() < P_CROSS)
		{
			need_cr[count] = i;
			count++;
		}
	}

	if(count % 2 != 0)
		count++;
		
	//�������һ����Ϊ0�Ľ����
	int cr_point = 0;
	while(cr_point == 0)
	{
		cr_point = m_round(rand_zo()*SOLU_DIM);
	}

	int temp[SOLU_DIM];

	//���н���
	for(i = 0;i < count;i+=2 )
	{
		for(j = cr_point;j < SOLU_DIM;j++)
		{
			temp[j] = new_pop[need_cr[i]][j];
			new_pop[need_cr[i]][j] = new_pop[need_cr[i+1]][j];
			new_pop[need_cr[i+1]][j] = temp[j];
		}
	}
}

/***����**/
void ga_mut(int pop[][SOLU_DIM])
{
	int ge_sum = POP_SIZE*SOLU_DIM;
	int i,j,k;
	for(i = 0; i < ge_sum;i++)
	{
		if(rand_zo() < P_MUT)
		{
			//��λ�˻������ڵ�Ⱦɫ��,�˴���Ⱦɫ�弴���壬��ͬ
			int chr_loc;
			chr_loc = i/SOLU_DIM;
			//��λ�˻�������Ⱦɫ���ϵĻ���λ
			int gen_loc;
			gen_loc = i%SOLU_DIM;
			//���б���
			pop[chr_loc][gen_loc] = m_round(rand_zo()*6);
		}
	}
}

double max(double h[],int len)
{
	double m = h[0];
	int i;
	for(i = 1;i < len;i++)
	{
		if(h[i] > m)
			m = h[i];
	}
	return m;
}
int  main()
{
	//������ɽ�
	int solu[POP_SIZE][SOLU_DIM];
	init_solu(solu);
	
	int i;

	double fit[POP_SIZE];

	get_fitness(solu,fit);
	printf("��ǰ����߷���Ϊ:%f  ",max(fit,POP_SIZE));

	printf("\n������........\n");

	for(i = 0; i < GEN_NUM;i++)
	{
		ga_sel(solu);
		ga_cross(solu);
		ga_mut(solu);
	}

	get_fitness(solu,fit);

	printf("���յ���߷���Ϊ:%f  ",max(fit,POP_SIZE));	
	printf("\n");
	return 0;
}


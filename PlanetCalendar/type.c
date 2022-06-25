#include "main.h"

void print_input_form()
{
	//default
	year = 2022;
	month = 4;
	day = 7;
	hour = 16;
	minute = 30;
	gender = 1; // 남자 1 여자 0

	//사용자 입력
	printf("year= ");
	scanf("%d", &year);
	printf("month= ");
	scanf("%d", &month);
	printf("day= ");
	scanf("%d", &day);
	printf("hour= ");
	scanf("%d", &hour);
	printf("minute= ");
	scanf("%d", &minute);
	printf("gender(m=1, f=0)= ");
	scanf("%d", &gender);
}

void cal_type_sign()
{ // 양 음
	char id[3];
	type_sign = 1;

	strncpy(id, saju[2], 2); 
	id[2] = '\0';
	if (!strcmp(id, "ga") || !strcmp(id, "by") || !strcmp(id, "mu") || !strcmp(id, "gy") || !strcmp(id, "im"))
		type_sign = 1; // 양
	else if (!strcmp(id, "eu") || !strcmp(id, "je") || !strcmp(id, "gi") || !strcmp(id, "sn") || !strcmp(id, "ge"))
		type_sign = 0; // 음
	printf("\ntype sign = %d", type_sign);
}

void cal_type_gs()
{ // 관성분류
	char id[3];

	strncpy(id, six_chin[1], 2);
	id[2] = '\0';
	if (!strcmp(id, "jg")){
		type_gs = 0;
		printf("\ntype gs = MV");  //월지정관
		return;
	}
	
	if (!strcmp(id, "pg")){
		type_gs = 1;
		printf("\ntype gs = MI");  //월지편관
		return;
	}
	strncpy(id, six_chin[2], 2);
	id[2] = '\0';
	if (!strcmp(id, "jg") || !strcmp(id, "pg")){
		type_gs = 2;
		printf("\ntype gs = MO");  //일지관성
		return;
	}
	strncpy(id, six_chin[0], 2);
	id[2] = '\0';
	if( !strcmp(id, "sg") || !strcmp(id, "pg") || !strcmp(id, "jg")){
		type_gs = 3;
		printf("\ntype gs = MN");   //연간지 관성
		return;
	}
	strncpy(id, six_chin[3], 2);
	id[2] = '\0';
	if( !strcmp(id, "sg") || !strcmp(id, "pg") || !strcmp(id, "jg")){
		type_gs = 3;
		printf("\ntype gs = MN");   //시간지 관성
		return;
	}
	strncpy(id, six_chin[1], 2);
	id[2] = '\0';
	if( !strcmp(id, "sg")){
		type_gs = 4;
		printf("\ntype gs = ME");   //월지상관무관
		return;
	}
	type_gs = 5;
	printf("\ntype gs = ML");  //무관
}

int is_cg_hc(char *id1, char *id2) //천간 합(2)충(1)
{
	if (!strcmp(id1, "ga"))
	{
		if (!strcmp(id2, "gi"))
			return (1);
		if (!strcmp(id2, "gy"))
			return (0);
	}
	if (!strcmp(id1, "eu"))
	{
		if (!strcmp(id2, "gy"))
			return (1);
		if (!strcmp(id2, "sn"))
			return (0);
	}
	if (!strcmp(id1, "by"))
	{
		if (!strcmp(id2, "sn"))
			return (1);
		if (!strcmp(id2, "im"))
			return (0);
	}
	if (!strcmp(id1, "je"))
	{
		if (!strcmp(id2, "im"))
			return (1);
		if (!strcmp(id2, "ge"))
			return (0);
	}
	if (!strcmp(id1, "mu"))
	{
		if (!strcmp(id2, "ge"))
			return (1);
	}
	if (!strcmp(id1, "gi"))
	{
		if (!strcmp(id2, "ga"))
			return (1);
	}
	if (!strcmp(id1, "gy"))
	{
		if (!strcmp(id2, "ga"))
			return (0);
		if (!strcmp(id2, "eu"))
			return (1);
	}
	if (!strcmp(id1, "sn"))
	{
		if (!strcmp(id2, "eu"))
			return (0);
		if (!strcmp(id2, "by"))
			return (1);
	}
	if (!strcmp(id1, "im"))
	{
		if (!strcmp(id2, "by"))
			return (0);
		if (!strcmp(id2, "je"))
			return (1);
	}
	if (!strcmp(id1, "ge"))
	{
		if (!strcmp(id2, "je"))
			return (0);
		if (!strcmp(id2, "mu"))
			return (1);
	}
	return (0);
}

int is_jj_hch(char *id1, char *id2) // 지지 합(2) 충(1) 형(3)
{
	if (!strcmp(id1, "ja"))
	{
		if (!strcmp(id2, "ch"))
			return (2);
		if (!strcmp(id2, "my"))
			return (3);
		if (!strcmp(id2, "ji"))
			return (2);
		if (!strcmp(id2, "oh"))
			return (1);
		if (!strcmp(id2, "si"))
			return (2);
	}
	if (!strcmp(id1, "ch"))
	{
		if (!strcmp(id2, "ja"))
			return (2);
		if (!strcmp(id2, "mi"))
			return (1);
		if (!strcmp(id2, "yu"))
			return (2);
		if (!strcmp(id2, "su"))
			return (3);
	}
	if (!strcmp(id1, "in"))
	{
		if (!strcmp(id2, "oh"))
			return (2);
		if (!strcmp(id2, "si"))
			return (1);
		if (!strcmp(id2, "ha"))
			return (2);
	}
	if (!strcmp(id1, "my"))
	{
		if (!strcmp(id2, "ja"))
			return (3);
		if (!strcmp(id2, "mi"))
			return (2);
		if (!strcmp(id2, "yu"))
			return (1);
		if (!strcmp(id2, "ha"))
			return (2);
	}
	if (!strcmp(id1, "ji"))
	{
		if (!strcmp(id2, "ja"))
			return (2);
		if (!strcmp(id2, "ji"))
			return (3);
		if (!strcmp(id2, "yu"))
			return (2);
		if (!strcmp(id2, "su"))
			return (1);
	}
	if (!strcmp(id1, "sa"))
	{
		if (!strcmp(id2, "si"))
			return (2);
		if (!strcmp(id2, "yu"))
			return (2);
		if (!strcmp(id2, "ha"))
			return (1);
	}
	if (!strcmp(id1, "oh"))
	{
		if (!strcmp(id2, "ja"))
			return (1);
		if (!strcmp(id2, "in"))
			return (2);
		if (!strcmp(id2, "oh"))
			return (3);
		if (!strcmp(id2, "mi"))
			return (2);
		if (!strcmp(id2, "su"))
			return (2);
	}
	if (!strcmp(id1, "mi"))
	{
		if (!strcmp(id2, "ch"))
			return (1);
		if (!strcmp(id2, "my"))
			return (2);
		if (!strcmp(id2, "oh"))
			return (2);
		if (!strcmp(id2, "su"))
			return (3);
	}
	if (!strcmp(id1, "si"))
	{
		if (!strcmp(id2, "ja"))
			return (2);
		if (!strcmp(id2, "in"))
			return (1);
		if (!strcmp(id2, "sa"))
			return (2);
	}
	if (!strcmp(id1, "yu"))
	{
		if (!strcmp(id2, "ch"))
			return (2);
		if (!strcmp(id2, "my"))
			return (1);
		if (!strcmp(id2, "ji"))
			return (2);
		if (!strcmp(id2, "yu"))
			return (3);
	}
	if (!strcmp(id1, "su"))
	{
		if (!strcmp(id2, "ch"))
			return (3);
		if (!strcmp(id2, "my"))
			return (2);
		if (!strcmp(id2, "oh"))
			return (2);
		if (!strcmp(id2, "mi"))
			return (3);
	}
	if (!strcmp(id1, "ha"))
	{
		if (!strcmp(id2, "in"))
			return (2);
		if (!strcmp(id2, "my"))
			return (2);
		if (!strcmp(id2, "sa"))
			return (1);
		if (!strcmp(id2, "ha"))
			return (3);
	}
	return (0);
}

void cal_type_hc()
{
	int i;
	int j;
	char id1[3];
	char id2[3];
	int cnt;
	int h=0; // 합
	int ch=0; // 충+형

	for (i=0; i<4; i++)
	{
		strncpy(id1, saju[i], 2);
		id1[2] = '\0';
		for (j=i+1; j<4; j++)
		{
			strncpy(id2, saju[j], 2);
			id1[2] = '\0';
			cnt = is_cg_hc(id1, id2);
			if (cnt == 2)
				h++;
			else if (cnt == 1)
				ch++;
		}
	}

	for (i=0; i<4; i++)
	{
		strncpy(id1, saju[i]+2, 2);
		id1[2] = '\0';
		for (j=i+1; j<4; j++)
		{
			strncpy(id2, saju[j]+2, 2);
			id1[2] = '\0';
			cnt = is_jj_hch(id1, id2);
			if (cnt == 2)
				h++;
			else if (cnt == 1 || cnt == 3)
				ch++;
		}
	}
	if (h > ch)
	{
		type_hc = 1;
		printf("\ntype hc = CR"); //합
	}
	else
	{
		type_hc = 0;
		printf("\ntype hc = CS"); // 충
	}
}

void cal_type_yn()
{
	char id1[3]; //일간
	char id2[3]; //월지
	char id3[3]; //일지

	strncpy(id1, saju[2], 2); //일간
	id1[2] = '\0';
	strncpy(id2, saju[1]+2, 2); //월지
	id2[2] = '\0';
	strncpy(id3, saju[2]+2, 2); //일지
	id3[2] = '\0';

	if (!strcmp(id1, "ga") ||!strcmp(id1, "mu") || !strcmp(id1, "gy"))
	{
		if (!strcmp(id2, "ch") ||!strcmp(id2, "mi") || !strcmp(id3, "ch") ||!strcmp(id3, "mi"))
		{
			type_yn = 1;
			printf("\ntype yn = SY");
			return;
		}
	}
	if (!strcmp(id1, "by") ||!strcmp(id1, "je"))
	{
		if (!strcmp(id2, "ha") ||!strcmp(id2, "yu") || !strcmp(id3, "ha") ||!strcmp(id3, "yu"))
		{
			type_yn = 1;
			printf("\ntype yn = SY");
			return;
		}
	}
	if (!strcmp(id1, "eu") ||!strcmp(id1, "gi"))
	{
		if (!strcmp(id2, "ja") ||!strcmp(id2, "si") || !strcmp(id3, "ja") ||!strcmp(id3, "si"))
		{
			type_yn = 1;
			printf("\ntype yn = SY");
			return;
		}
	}
	if (!strcmp(id1, "sn"))
	{
		if (!strcmp(id2, "oh") ||!strcmp(id2, "in") || !strcmp(id3, "oh") ||!strcmp(id3, "in"))
		{
			type_yn = 1;
			printf("\ntype yn = SY");
			return;
		}
	}
	if (!strcmp(id1, "im") ||!strcmp(id1, "ge"))
	{
		if (!strcmp(id2, "sa") ||!strcmp(id2, "my") || !strcmp(id3, "sa") ||!strcmp(id3, "my"))
		{
			type_yn = 1;
			printf("\ntype yn = SY");
			return;
		}
	}
	type_yn = 0;
	printf("\ntype yn = SN");
}

int cal_type_result()
{
	switch(type_gs)
	{
		case 0: //mv
			if (type_sign*type_hc*type_yn == 1)
				return (1); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (2); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (3); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (4); // 0 1 1
			else if (type_sign == 1)
				return (5); // 1 0 0
			else if (type_hc == 1)
				return (6); // 0 1 0
			else 
				return (7); // 0 0 1
		case 1: //mi
			if (type_sign*type_hc*type_yn == 1)
				return (8); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (9); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (10); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (11); // 0 1 1
			else if (type_sign == 1)
				return (12); // 1 0 0
			else if (type_hc == 1)
				return (13); // 0 1 0
			else 
				return (14); // 0 0 1
		case 2: //mo
			if (type_sign*type_hc*type_yn == 1)
				return (15); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (16); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (17); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (18); // 0 1 1
			else if (type_sign == 1)
				return (19); // 1 0 0
			else if (type_hc == 1)
				return (20); // 0 1 0
			else 
				return (21); // 0 0 1
		case 3: //mn
			if (type_sign*type_hc*type_yn == 1)
				return (22); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (23); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (24); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (25); // 0 1 1
			else if (type_sign == 1)
				return (26); // 1 0 0
			else if (type_hc == 1)
				return (27); // 0 1 0
			else 
				return (28); // 0 0 1
		case 4: //me
			if (type_sign*type_hc*type_yn == 1)
				return (29); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (30); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (31); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (32); // 0 1 1
			else if (type_sign == 1)
				return (33); // 1 0 0
			else if (type_hc == 1)
				return (34); // 0 1 0
			else 
				return (35); // 0 0 1
		case 5: //ml
			if (type_sign*type_hc*type_yn == 1)
				return (36); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (37); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (38); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (39); // 0 1 1
			else if (type_sign == 1)
				return (40); // 1 0 0
			else if (type_hc == 1)
				return (41); // 0 1 0
			else 
				return (42); // 0 0 1
	}
}
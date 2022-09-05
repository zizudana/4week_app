#include "main.h"

void print_input_form()
{
	//default
	year = 2022;
	month = 4;
	day = 7;
	hour = 15;
	minute = 0;
	gender = 0; // 남자 1 여자 0
	int time_know = 0;

	//사용자 입력
	printf("year= ");
	scanf("%d", &year);
	printf("month= ");
	scanf("%d", &month);
	printf("day= ");
	scanf("%d", &day);
	printf("gender(m=1, f=0)= ");
	scanf("%d", &gender);
	printf("know the time? 1 or 0");
	scanf("%d", &time_know);
	if (gender)
		time_know_m = time_know;
	else
		time_know_w = time_know;
	if (time_know)
	{
		printf("hour= ");
		scanf("%d", &hour);
		printf("minute= ");
		scanf("%d", &minute);
	}
}

int cal_type_sign(int s)
{ // 양 음
	char id[3];
	type_sign = 1;

	if (s)
		strncpy(id, saju2[2], 2); 
	else
		strncpy(id, saju[2], 2);
	id[2] = '\0';
	if (!strcmp(id, "ga") || !strcmp(id, "by") || !strcmp(id, "mu") || !strcmp(id, "gy") || !strcmp(id, "im"))
		type_sign = 1; // 양
	else if (!strcmp(id, "eu") || !strcmp(id, "je") || !strcmp(id, "gi") || !strcmp(id, "sn") || !strcmp(id, "ge"))
		type_sign = 0; // 음
	//printf("\ntype sign = %d\n", type_sign);
	return (type_sign);
}

void cal_type_gs_w()
{ // 관성분류(여자)
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
	if (time_know)
	{
		strncpy(id, six_chin[3], 2);
		id[2] = '\0';
		if( !strcmp(id, "sg") || !strcmp(id, "pg") || !strcmp(id, "jg")){
			type_gs = 3;
			printf("\ntype gs = MN");   //시간지 관성
			return;
		}
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

void cal_type_gs_m()
{ // 관성분류(남자)
	char id[3];

	strncpy(id, six_chin[1], 2);
	id[2] = '\0';
	if (!strcmp(id, "jj")){
		type_gs = 0;
		printf("\ntype gs = MV");  //월지정관
		return;
	}
	
	if (!strcmp(id, "pj")){
		type_gs = 1;
		printf("\ntype gs = MI");  //월지편관
		return;
	}
	strncpy(id, six_chin[2], 2);
	id[2] = '\0';
	if (!strcmp(id, "jj") || !strcmp(id, "pj")){
		type_gs = 2;
		printf("\ntype gs = MO");  //일지관성
		return;
	}
	strncpy(id, six_chin[0], 2);
	id[2] = '\0';
	if( !strcmp(id, "gj") || !strcmp(id, "pj") || !strcmp(id, "jj")){
		type_gs = 3;
		printf("\ntype gs = MN");   //연간지 관성
		return;
	}
	if (time_know)
	{
		strncpy(id, six_chin[3], 2);
		id[2] = '\0';
		if( !strcmp(id, "gj") || !strcmp(id, "pj") || !strcmp(id, "jj")){
			type_gs = 3;
			printf("\ntype gs = MN");   //시간지 관성
			return;
		}
	}
	strncpy(id, six_chin[1], 2);
	id[2] = '\0';
	if( !strcmp(id, "gj")){
		type_gs = 4;
		printf("\ntype gs = ME");   //월지상관무관
		return;
	}
	type_gs = 5;
	printf("\ntype gs = ML");  //무관
}

int print_h(char *id1, char *id2)
{
	printf("%s and %s is h\n", id1, id2);
	return (2);
}

int print_c(char *id1, char *id2)
{
	printf("%s and %s is c\n", id1, id2);
	return (1);
}

int is_cg_hc(char *id1, char *id2) //천간 합(2)충(1)
{
	if (!strcmp(id1, "ga"))
	{
		if (!strcmp(id2, "gi"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "gy"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "eu"))
	{
		if (!strcmp(id2, "gy"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "sn"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "by"))
	{
		if (!strcmp(id2, "sn"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "im"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "je"))
	{
		if (!strcmp(id2, "im"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "ge"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "mu"))
	{
		if (!strcmp(id2, "ge"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "gi"))
	{
		if (!strcmp(id2, "ga"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "gy"))
	{
		if (!strcmp(id2, "ga"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "eu"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "sn"))
	{
		if (!strcmp(id2, "eu"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "by"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "im"))
	{
		if (!strcmp(id2, "by"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "je"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "ge"))
	{
		if (!strcmp(id2, "je"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "mu"))
			return (print_h(id1, id2));
	}
	return (0);
}

int is_jj_hc(char *id1, char *id2) // 지지 합(2) 충,형(1)
{
	if (!strcmp(id1, "ja"))
	{
		if (!strcmp(id2, "ch"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "my"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ji"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "oh"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "si"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "ch"))
	{
		if (!strcmp(id2, "ja"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "mi"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "yu"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "su"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "in"))
	{
		if (!strcmp(id2, "oh"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "si"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ha"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "my"))
	{
		if (!strcmp(id2, "ja"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "mi"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "yu"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ha"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "ji"))
	{
		if (!strcmp(id2, "ja"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "ji"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "yu"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "su"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "sa"))
	{
		if (!strcmp(id2, "si"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "yu"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "ha"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "oh"))
	{
		if (!strcmp(id2, "ja"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "in"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "oh"))
			return (3);
		if (!strcmp(id2, "mi"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "su"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "mi"))
	{
		if (!strcmp(id2, "ch"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "my"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "oh"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "su"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "si"))
	{
		if (!strcmp(id2, "ja"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "in"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "sa"))
			return (print_h(id1, id2));
	}
	if (!strcmp(id1, "yu"))
	{
		if (!strcmp(id2, "ch"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "my"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ji"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "yu"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "su"))
	{
		if (!strcmp(id2, "ch"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "my"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "oh"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "mi"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ji"))
			return (print_c(id1, id2));
	}
	if (!strcmp(id1, "ha"))
	{
		if (!strcmp(id2, "in"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "my"))
			return (print_h(id1, id2));
		if (!strcmp(id2, "sa"))
			return (print_c(id1, id2));
		if (!strcmp(id2, "ha"))
			return (print_c(id1, id2));
	}
	return (0);
}

void cal_type_hc()
{
	int i;
	int j;
	char id1[3];
	char id2[3];
	int h; // 합
	int ch; // 충+형
	int cnt;

	h = 0;
	ch = 0;
	if (time_know)
	{
		for (i=0; i<3; i++)
		{
			if (gender)
				strncpy(id1, saju2[i], 2);
			else
				strncpy(id1, saju[i], 2);
			id1[2] = '\0';
			for (j=i+1; j<4; j++)
			{
				if (gender)
					strncpy(id2, saju2[j], 2);
				else
					strncpy(id2, saju[j], 2);
				id2[2] = '\0';
				cnt = is_cg_hc(id1, id2);
				if (cnt == 2)
					h++;
				else if (cnt == 1)
					ch++;
			}
		}

		for (i=0; i<3; i++)
		{
			if (gender)
				strncpy(id1, saju2[i]+2, 2);
			else
				strncpy(id1, saju[i]+2, 2);
			id1[2] = '\0';
			for (j=i+1; j<4; j++)
			{
				if (gender)
					strncpy(id2, saju2[j]+2, 2);
				else
					strncpy(id2, saju[j]+2, 2);
				id2[2] = '\0';
				cnt = is_jj_hc(id1, id2);
				if (cnt == 2)
					h++;
				else if (cnt == 1)
					ch++;
			}
		}
	}

	else // 시간을 모를때
	{
		if (gender)
			strncpy(id1, saju2[0], 2);
		else
			strncpy(id1, saju[0], 2);
		id1[2] = '\0';
		if (gender)
			strncpy(id2, saju2[1], 2);
		else
			strncpy(id2, saju[1], 2);
		id2[2] = '\0';
		cnt = is_cg_hc(id1, id2);
		if (cnt == 2)
			h++;
		else if (cnt == 1)
			ch++;

		for (i=0; i<2; i++)
		{
			if (gender)
				strncpy(id1, saju2[i]+2, 2);
			else
				strncpy(id1, saju[i]+2, 2);
			id1[2] = '\0';
			for (j=i+1; j<3; j++)
			{
				if (gender)
					strncpy(id2, saju2[j]+2, 2);
				else
					strncpy(id2, saju[j]+2, 2);
				id2[2] = '\0';
				cnt = is_jj_hc(id1, id2);
				if (cnt == 2)
					h++;
				else if (cnt == 1)
					ch++;
			}
		}
	}

	if (h >= ch)
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

	if (gender)
	{
		strncpy(id1, saju2[2], 2); //일간
		id1[2] = '\0';
		strncpy(id2, saju2[1]+2, 2); //월지
		id2[2] = '\0';
		strncpy(id3, saju2[2]+2, 2); //일지
		id3[2] = '\0';
	}
	else
	{
		strncpy(id1, saju[2], 2); //일간
		id1[2] = '\0';
		strncpy(id2, saju[1]+2, 2); //월지
		id2[2] = '\0';
		strncpy(id3, saju[2]+2, 2); //일지
		id3[2] = '\0';
	}

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
			else if (type_yn == 1)
				return (7); // 0 0 1
			else 
				return (8); // 0 0 0
		case 1: //mi
			if (type_sign*type_hc*type_yn == 1)
				return (9); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (10); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (11); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (12); // 0 1 1
			else if (type_sign == 1)
				return (13); // 1 0 0
			else if (type_hc == 1)
				return (14); // 0 1 0
			else if (type_yn == 1)
				return (15); // 0 0 1
			else 
				return (16); // 0 0 0
		case 2: //mo
			if (type_sign*type_hc*type_yn == 1)
				return (17); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (18); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (19); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (20); // 0 1 1
			else if (type_sign == 1)
				return (21); // 1 0 0
			else if (type_hc == 1)
				return (22); // 0 1 0
			else if (type_yn == 1)
				return (23); // 0 0 1
			else 
				return (24); // 0 0 0
		case 3: //mn
			if (type_sign*type_hc*type_yn == 1)
				return (25); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (26); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (27); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (28); // 0 1 1
			else if (type_sign == 1)
				return (29); // 1 0 0
			else if (type_hc == 1)
				return (30); // 0 1 0
			else if (type_yn == 1)
				return (31); // 0 0 1
			else 
				return (32); // 0 0 0
		case 4: //me
			if (type_sign*type_hc*type_yn == 1)
				return (33); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (34); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (35); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (36); // 0 1 1
			else if (type_sign == 1)
				return (37); // 1 0 0
			else if (type_hc == 1)
				return (38); // 0 1 0
			else if (type_yn == 1)
				return (39); // 0 0 1
			else 
				return (40); // 0 0 0
		case 5: //ml
			if (type_sign*type_hc*type_yn == 1)
				return (41); // 1 1 1
			else if (type_sign*type_hc == 1)
				return (42); // 1 1 0
			else if (type_sign*type_yn == 1)
				return (43); // 1 0 1
			else if (type_hc*type_yn == 1)
				return (44); // 0 1 1
			else if (type_sign == 1)
				return (45); // 1 0 0
			else if (type_hc == 1)
				return (46); // 0 1 0
			else if (type_yn == 1)
				return (47); // 0 0 1
			else 
				return (48); // 0 0 0
	}
}
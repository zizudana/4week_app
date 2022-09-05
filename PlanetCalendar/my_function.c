#include "main.h"


// 시간조견표 
char *time_table[5][12] = 
{
	{"gaja","euch","byin","jemy","muji","gisa","gyoh","snmi","imsi","geyu","gasu","euha"},
	{"byja","jech","muin","gimy","gyji","snsa","imoh","gemi","gasi","euyu","bysu","jeha"},
	{"muja","gich","gyin","snmy","imji","gesa","gaoh","eumi","bysi","jeyu","musu","giha"},
	{"gyja","snch","imin","gemy","gaji","eusa","byoh","jemi","musi","giyu","gysu","snha"},
	{"imja","gech","gain","eumy","byji","jesa","muoh","gimi","gysi","snyu","imsu","geha"}
};

// 십이운성
char *twelve_star[8][12] =
{
	{"gl","jy","so","by","sa","mo","je","ta","ya","js","my","gd"},
	{"jy","gl","gd","my","js","ya","ta","je","mo","sa","by","so"},
	{"js","my","gd","gl","jy","so","by","sa","mo","je","ta","ya"},
	{"sa","by","so","jy","gl","gd","my","js","ya","ta","je","mo"},
	{"je","ta","ya","js","my","gd","gl","jy","so","by","sa","mo"},
	{"ta","je","mo","sa","by","so","jy","gl","gd","my","js","ya"},
	{"by","sa","mo","je","ta","ya","js","my","gd","gl","jy","so"},
	{"my","js","ya","ta","je","mo","sa","by","so","jy","gl","gd"}
};

// 천간의 육신 조견표
char *six_sin[10][10] =
{
	{"bg","gj","ss","sg","pj","jj","pg","jg","pi","ji"},
	{"gj","bg","sg","ss","jj","pj","jg","pg","ji","pi"},
	{"pi","ji","bg","gj","ss","sg","pj","jj","pg","jg"},
	{"ji","pi","gj","bg","sg","ss","jj","pj","jg","pg"},
	{"pg","jg","pi","ji","bg","gj","ss","sg","pj","jj"},
	{"jg","pg","ji","pi","gj","bg","sg","ss","jj","pj"},
	{"pj","jj","pg","jg","pi","ji","bg","gj","ss","sg"},
	{"jj","pj","jg","pg","ji","pi","gj","bg","sg","ss"},
	{"ss","sg","pj","jj","pg","jg","pi","ji","bg","gj"},
	{"sg","ss","jj","pj","jg","pg","ji","pi","gj","bg"}
};

void print_time_table()
{
	char id[3]; // 일천간
	int id_x;
	int id_y;
	int temp;

	if (gender)
		strncpy(id, saju2[2], 2);
	else
		strncpy(id, saju[2], 2);
	id[2] = '\0';
	if (hour == 23)
	{
		if (minute < 30)
			id_y = 11;
		else
			id_y = 0;
	}
	else
	{
		temp = hour * 60 + minute;
		if (temp >= 0 && temp < 90)
			id_y = 0;
		if (temp >= 90 && temp < 210)
			id_y = 1;
		if (temp >= 210 && temp < 330)
			id_y = 2;
		if (temp >= 330 && temp < 450)
			id_y = 3;
		if (temp >= 450 && temp < 570)
			id_y = 4;
		if (temp >= 570 && temp < 690)
			id_y = 5;
		if (temp >= 690 && temp < 810)
			id_y = 6;
		if (temp >= 810 && temp < 930)
			id_y = 7;
		if (temp >= 930 && temp < 1050)
			id_y = 8;
		if (temp >= 1050 && temp < 1170)
			id_y = 9;
		if (temp >= 1170 && temp < 1290)
			id_y = 10;
		if (temp >= 1290 && temp < 1380) //11시 전까지
			id_y = 11;
	}
	if (!strcmp(id,"ga") || !strcmp(id,"gi"))
		id_x = 0;
	if (!strcmp(id,"eu") || !strcmp(id,"gy"))
		id_x = 1;
	if (!strcmp(id,"by") || !strcmp(id,"sn"))
		id_x = 2;
	if (!strcmp(id,"je") || !strcmp(id,"im"))
		id_x = 3;
	if (!strcmp(id,"mu") || !strcmp(id,"ge"))
		id_x = 4;
	printf("time=%s\n", time_table[id_x][id_y]);
	if (gender)
		strncpy(saju2[3], time_table[id_x][id_y], 4);
	else
		strncpy(saju[3], time_table[id_x][id_y], 4);
}


void print_twelve_star()
{
	char id[3]; // 일천간
	char zz[4][3];
	int id_x;
	int id_y;
	strncpy(id, saju[2], 2);
	id[2] ='\0';
	if (!strcmp(id, "ga"))
		id_x = 0;
	if (!strcmp(id, "eu"))
		id_x = 1;
	if (!strcmp(id, "by") || !strcmp(id, "mu"))
		id_x = 2;
	if (!strcmp(id, "je") || !strcmp(id, "gi"))
		id_x = 3;
	if (!strcmp(id, "gy"))
		id_x = 4;
	if (!strcmp(id, "sn"))
		id_x = 5;
	if (!strcmp(id, "im"))
		id_x = 6;
	if (!strcmp(id, "ge"))
		id_x = 7;
	printf("-----------------------------\n");
	printf("<twelve star>\n");
	for(int i=0;i<4;i++)
	{
		strncpy(zz[i], saju[i]+2, 2);
		zz[i][2] = '\0';
		if (!strcmp(zz[i], "in"))
			id_y = 0;
		if (!strcmp(zz[i], "my"))
			id_y = 1;
		if (!strcmp(zz[i], "ji"))
			id_y = 2;
		if (!strcmp(zz[i], "sa"))
			id_y = 3;
		if (!strcmp(zz[i], "oh"))
			id_y = 4;
		if (!strcmp(zz[i], "mi"))
			id_y = 5;
		if (!strcmp(zz[i], "si"))
			id_y = 6;
		if (!strcmp(zz[i], "yu"))
			id_y = 7;
		if (!strcmp(zz[i], "su"))
			id_y = 8;
		if (!strcmp(zz[i], "ha"))
			id_y = 9;
		if (!strcmp(zz[i], "ja"))
			id_y = 10;
		if (!strcmp(zz[i], "ch"))
			id_y = 11;
		printf("%s ", twelve_star[id_x][id_y]);
	}
	printf("\n");
}


int six_sin_x(char id[])
{
	int id_x;

	if (!strcmp(id, "ga"))
		id_x = 0;
	if (!strcmp(id, "eu"))
		id_x = 1;
	if (!strcmp(id, "by"))
		id_x = 2;
	if (!strcmp(id, "je"))
		id_x = 3;
	if (!strcmp(id, "mu"))
		id_x = 4;
	if (!strcmp(id, "gi"))
		id_x = 5;
	if (!strcmp(id, "gy"))
		id_x = 6;
	if (!strcmp(id, "sn"))
		id_x = 7;
	if (!strcmp(id, "im"))
		id_x = 8;
	if (!strcmp(id, "ge"))
		id_x = 9;
	return (id_x);
}


int six_sin_y(char id[])
{
	int id_y;

	if (!strcmp(id, "ga") || !strcmp(id, "in"))
		id_y = 0;
	if (!strcmp(id, "eu") || !strcmp(id, "my"))
		id_y = 1;
	if (!strcmp(id, "by") || !strcmp(id, "sa"))
		id_y = 2;
	if (!strcmp(id, "je") || !strcmp(id, "oh"))
		id_y = 3;
	if (!strcmp(id, "mu") || !strcmp(id, "ji") || !strcmp(id, "su"))
		id_y = 4;
	if (!strcmp(id, "gi") || !strcmp(id, "ch") || !strcmp(id, "mi"))
		id_y = 5;
	if (!strcmp(id, "gy") || !strcmp(id, "si"))
		id_y = 6;
	if (!strcmp(id, "sn") || !strcmp(id, "yu"))
		id_y = 7;
	if (!strcmp(id, "im") || !strcmp(id, "ha"))
		id_y = 8;
	if (!strcmp(id, "ge") || !strcmp(id, "ja"))
		id_y = 9;
	return (id_y);
}


void print_six_sin()
{
	char id1[3];
	char id2[3];
	int id_x;
	int id_y;
	int i;
	int cnt;

	if (gender)
		strncpy(id1, saju2[2], 2); //일천간
	else
		strncpy(id1, saju[2], 2);
	id1[2] = '\0';
	id_x = six_sin_x(id1);
	cnt = 0;
	for (i=0; i<4; i++) //일천+지지4개
	{
		if (gender)
			strncpy(id2, saju2[i]+2, 2);
		else
			strncpy(id2, saju[i]+2, 2);
		id2[2] = '\0';
		id_y = six_sin_y(id2);
		strncpy(six_chin[cnt], six_sin[id_x][id_y], 2);
		six_chin[cnt++][3] = '\0';
	}
	for (i=0;i<2;i++) //일천+년천,월천
	{
		if (gender)
			strncpy(id2, saju2[i], 2);
		else
			strncpy(id2, saju[i], 2);
		id2[2] = '\0';
		id_y = six_sin_y(id2);
		strncpy(six_chin[cnt], six_sin[id_x][id_y], 2);
		six_chin[cnt++][3] = '\0';
	}
	if (gender)
		strncpy(id2, saju2[3], 2); //일천+시천
	else
		strncpy(id2, saju[3], 2); //일천+시천
	id2[2] = '\0';
	id_y = six_sin_y(id2);
	strncpy(six_chin[cnt], six_sin[id_x][id_y], 2);
	six_chin[cnt++][3] = '\0';

	if (gender)
		strncpy(id1, saju2[3], 2); //시천+년천
	else
		strncpy(id1, saju[3], 2); //시천+년천
	id1[2] = '\0';
	id_x = six_sin_x(id1);
	if (gender)
		strncpy(id2, saju2[0], 2);
	else
		strncpy(id2, saju[0], 2);
	id2[2] = '\0';
	id_y = six_sin_y(id2);
	strncpy(six_chin[cnt], six_sin[id_x][id_y], 2);
	six_chin[cnt++][3] = '\0';
	printf("-----------------------------\n");
	printf("<six chin>\n");
	for (i=4; i<8; i++)
		printf("%s ", six_chin[i]);
	printf("\n");
	for(i=0; i<4; i++)
		printf("%s ", six_chin[i]);
	printf("\n-----------------------------");
}

void print_great_fortune(int direction)
{
	int i;
	int j;
	char id1[3];
	char id2[3];
	char *gan[] = {"ga","eu","by","je","mu","gi","gy","sn","im","ge"};
	char *ji[] = {"ja","ch","in","my","ji","sa","oh","mi","si","yu","su","ha"};
	int start1;
	int start2;

	strncpy(id1, saju[1], 2); //월천간
	strncpy(id2, saju[1]+2, 2); //월지지
	id1[2] = '\0';
	id2[2] = '\0';
	for (i=0; i<10; i++)
	{
		if (!strcmp(id1, gan[i]))
			start1 = i;
	}
	for (i=0; i<12; i++)
	{
		if (!strcmp(id2, ji[i]))
			start2 = i;
	}
	if (direction) //순행
	{
		for (j=0;j<10;j++)
		{
			start1 += 1;
			if (start1 == 10)
				start1 = 0;
			strncpy(gf_gan[j], gan[start1], 2);
			gf_gan[j][2] = '\0';
		}
		for (j=0;j<10;j++)
		{
			start2 += 1;
			if (start2 == 12)
				start2 = 0;
			strncpy(gf_ji[j], ji[start2], 2);
			gf_ji[j][2] = '\0';
		}
	}
	else //역행
	{
		for (j=0;j<10;j++)
		{
			start1 -= 1;
			if (start1 == -1)
				start1 = 9;
			strncpy(gf_gan[j], gan[start1], 2);
			gf_gan[j][2] = '\0';
		}
		for (j=0;j<10;j++)
		{
			start2 -= 1;
			if (start2 == -1)
				start2 = 11;
			strncpy(gf_ji[j], ji[start2], 2);
			gf_ji[j][2] = '\0';
		}
	}
	printf("<great fortune>\n");
	for (j=0; j<10; j++)
		printf("%s ", gf_gan[j]);
	printf("\n");
	for (j=0; j<10; j++)
		printf("%s ", gf_ji[j]);
}

void calculate_great_foutune()
{
	char id[3];
	int sign;
	int direction;
	int fortune_num; //대운수
	double total;

	strncpy(id, saju[0], 2); //년천간
	id[2] = '\0';
	if (!strcmp(id, "ga") || !strcmp(id, "by") || !strcmp(id, "mu") || !strcmp(id, "gy") || !strcmp(id, "im"))
		sign = 1;
	if (!strcmp(id, "eu") || !strcmp(id, "je") || !strcmp(id, "gi") || !strcmp(id, "sn") || !strcmp(id, "ge"))
		sign = 0;
	if (sign) //양일때
		direction = gender ? 1 : 0; //남자면 순행
	else //음일때
		direction = gender ? 0 : 1; //남자면 역행

	if (direction) // 순행일때
	{
		if (month_flag)
			total = calculate_day(smonth_info[1].ingi.date.year, smonth_info[1].ingi.date.month, smonth_info[1].ingi.date.day) - calculate_day(year, month, day);
		else
			total = calculate_day(umonth_info[1].ingi.date.year, umonth_info[1].ingi.date.month, umonth_info[1].ingi.date.day) - calculate_day(year, month, day);
	}
	else // 역행일때
	{
		if (month_flag)
			total = calculate_day(year, month, day) - calculate_day(umonth_info[0].ingi.date.year, umonth_info[0].ingi.date.month, umonth_info[0].ingi.date.day);
		else
			total = calculate_day(year, month, day) - calculate_day(smonth_info[1].ingi.date.year, smonth_info[1].ingi.date.month, smonth_info[1].ingi.date.day);
	}
	total = total / 3.0;
	fortune_num = (int)(total+0.5); //나누기3의 반올림
	printf("\nnum = %d\n", fortune_num);
	print_great_fortune(direction);
}

void great_six_chin()
{
	char id1[3];
	char id2[3];
	int id_x;
	int id_y;
	int i;
	int cnt;

	strncpy(id1, saju[2], 2); //일천간
	id1[2] = '\0';
	id_x = six_sin_x(id1);
	cnt=0;
	for (i=0; i<10; i++)
	{
		strncpy(id2, gf_gan[i], 2);
		id2[2] = '\0';
		id_y = six_sin_y(id2);
		strncpy(gf_six_gan[cnt], six_sin[id_x][id_y], 2);
		gf_six_gan[cnt++][3] = '\0';
	}
	cnt = 0;
	for (i=0; i<10; i++)
	{
		strncpy(id2, gf_ji[i], 2);
		id2[2] = '\0';
		id_y = six_sin_y(id2);
		strncpy(gf_six_ji[cnt], six_sin[id_x][id_y], 2);
		gf_six_ji[cnt++][3] = '\0';
	}
	printf("\n-----------------------------\n");
	for (i=0; i<10; i++)
		printf("%s ", gf_six_gan[i]);
	printf("\n");
	for(i=0; i<10; i++)
		printf("%s ", gf_six_ji[i]);
	printf("\n-----------------------------");
}

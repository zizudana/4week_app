#include "main.h"
/*
void print_month_info()
{
	//printf("this month middle=%s\n",get_string_time_local(smonth_info[1].mingi.date,timez_off));
	//ingi_day=smonth_info[0].outgi.date.day;
	//이번달 절입, 이전달 절입, 다음달 절입
	printf("this month first=%s\n",get_string_time_local(smonth_info[1].ingi.date,timez_off));
	printf("before month first= %s\n", get_string_time_local(umonth_info[0].ingi.date,timez_off));
	printf("next month first= %s\n", get_string_time_local(umonth_info[1].ingi.date,timez_off));
}
*/

int main()
{
	//default
	year=2016;
	month=5;
	timez_off=-540;
	month_flag = 0;

	time_t ltime;
	struct tm *today,*gmt_time;
	int tzoffset;

	time(&ltime);
	today=localtime(&ltime);

	year=today->tm_year+1900;
	month=today->tm_mon+1;

	cur_time.year=today->tm_year + 1900;
	cur_time.month=today->tm_mon + 1;
	cur_time.day=today->tm_mday;
	cur_time.hour=today->tm_hour;
	cur_time.min=today->tm_min;
	cur_time_sec=today->tm_sec;

	gmt_time=gmtime(&ltime);

	timez_off=getminbytime(gmt_time->tm_year+1900,gmt_time->tm_mon+1,gmt_time->tm_mday ,gmt_time->tm_hour,gmt_time->tm_min,
			cur_time.year,cur_time.month,cur_time.day ,cur_time.hour,cur_time.min);

  int i,in_st_no ;
  int cnt;
  char *buf;
  char *tmp;
  char *d[20];
	int time_year_system=1;

	print_body_first(); //input 실행
	print_month_table(); // 일주계산, saju[2]
	print_time_table(); // 시주계산, saju[3]
	print_twelve_star();
	print_six_sin();
	calculate_great_foutune();
	great_six_chin();
	cal_type_sign(); // 양음 계산, type_sign
	cal_type_gs(); // 관성 계산
	cal_type_hc(); // 합충 계산
	cal_type_yn(); //민감도 계산
	type_result = cal_type_result();
	printf("\ntype = %d", type_result);

	return(0);
}
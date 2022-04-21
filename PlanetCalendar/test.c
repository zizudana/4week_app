#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "cal20000_calculation_type.h"
#include "cal_calculation.h"

int year,month,day,timez_off,lang;
int day_value[31][26];
so24term_month smonth_info[2];
moon_info lmonth_info[3];

date_cal cur_time, cur_time_tz;
int cur_time_sec;

void check_planet_event_month(int wbyear, int wbmonth, int time_offset_chkevent)
{
	int i,j;

	event_result_count_over=false;
	event_result_count=0;

	for(i=0;i<14;i++)
	{
		Planet_event_process_event[i]=true;;
	}

	for(i=1;i<9;i++)
	{
		Planet_event_process[i]=true;
	}

	date_cal start_date,end_date,date_temp,current_time;

	date_temp.year=wbyear;
	date_temp.month=wbmonth;
	date_temp.day=1;
	date_temp.hour=0;
	date_temp.min=0;


	start_date=getdatebymin( -540-time_offset_chkevent, date_temp);

	date_temp.year=wbyear;
	date_temp.month=wbmonth+1;
	if (date_temp.month==13)
	{
		date_temp.year=wbyear+1;
		date_temp.month=1;
	}
	date_temp.day=1;
	date_temp.hour=0;
	date_temp.min=0;

	end_date=getdatebymin( -540-time_offset_chkevent, date_temp);

	long long local_duration=getminbytime(end_date.year,end_date.month,end_date.day,end_date.hour,end_date.min,
			                start_date.year,start_date.month,start_date.day,start_date.hour,start_date.min
			             )-1;

	int tmin_add;
	int remain_duration=(int)local_duration+1;



	int tmin;
	for(tmin=0;tmin<(local_duration+1);)
	{

		current_time=getdatebymin(-1*tmin, start_date);

		calc_current_planet_position( current_time, &moon_node[1],&moon_perigee[1],&moon_apogee[1],&moon_distance[1]);
		for(j=0;j<9;j++)
			planet_position[j][1]=calc_planet_position_calc[j];


		if (tmin==0)
		{
			for(j=0;j<9;j++)
			{
				planet_position[j][0]=calc_planet_position_calc[j];
				planet_position[j][prev_1]=calc_planet_position_calc[j];
				if (j==1)
				{
					moon_node[0]=moon_node[1];
					moon_perigee[0]=moon_perigee[1];
					moon_apogee[0]=moon_apogee[1];
					moon_distance[0]=moon_distance[1];
				}
			}

		}
		else
		{
			depth_count=0;
			chk_stationary_and_great_elong=true;
			chk_planet_events_not_stat_greatelong=true;
			check_planet_event(0);
		}


		for(j=0;j<9;j++)
		{
			planet_position[j][prev_1]=planet_position[j][0];
			planet_position[j][0]=planet_position[j][1];

			if (j==1)
			{
				moon_node[0]=moon_node[1];
				moon_perigee[0]=moon_perigee[1];
				moon_apogee[0]=moon_apogee[1];
				moon_distance[0]=moon_distance[1];
			}
		}


		if (remain_duration>1024) tmin_add=1024;
		else
		if (remain_duration>512) tmin_add=512;
		else if (remain_duration>256) tmin_add=256;
		else if (remain_duration>128) tmin_add=128;
		else if (remain_duration>64) tmin_add=64;
		else if (remain_duration>32) tmin_add=32;
		else if (remain_duration>16) tmin_add=16;
		else if (remain_duration>8) tmin_add=8;
		else if (remain_duration>4) tmin_add=4;
		else tmin_add=1;


		tmin+=tmin_add;
		remain_duration-=tmin_add;


	} // for(int tmin=0;tmin<(local_duration+1);)


}

void print_input_form()
{
	int i;
	int year;
	int month;

	//사용자 입력
	year = 2022;
	month = 4;
	day = 5;
}

void print_body_first()
{
	int pyear,pmonth,nmonth,nyear;

	pmonth=month-1;
	pyear=year;
	if (pmonth==0)
	{
		pmonth=12;
		pyear=pyear-1;
		if (pyear==-10000)
		{
			pyear=-9999;
			pmonth=1;
		}
	}
	nmonth=month+1;
	nyear=year;
	if (nmonth==13)
	{
		nmonth=1;
		nyear=nyear+1;
		if (nyear==10001)
		{
			nyear=10000;
			nmonth=12;
		}
	}
	int less_year=year-1;
	if (less_year==-10000) less_year=-9999;
	int more_year=year+1;
	if (more_year==10000) less_year=9999;
	print_input_form();
}

void print_month_table()
{

	date_cal test_date1,test_date2;

	lunar_month lunar_date;

	int month_lastday;
	int easter_month,easter_day;

	lunar_date=solortolunar(2014,6,27);

    int next_year=year;
    int next_month=month+1;
    if (next_month==13)
    {
    	next_month=1;
    	next_year=next_year+1;
    }

    test_date1.year=next_year;
    test_date1.month=next_month;
    test_date1.day=1;
    test_date1.hour=0;
    test_date1.min=0;

    test_date2=getdatebymin(200,test_date1);

    month_lastday=test_date2.day;

    lunar_date=solortolunar(year,month,1);

    int lmv=0;
    lmonth_info[lmv]=lunar_date.moon;

    test_date1.year=year;
    test_date1.month=month-1;
	if ((month-1)==0)
	{
		test_date1.year=year-1;
		test_date1.month=12;
	}
	test_date1.day=15;
	test_date1.hour=0;
	test_date1.min=0;

	smonth_info[0]=SolortoSo24(test_date1);  //양력1일날의 절기

    test_date1.year=year;
    test_date1.month=month;
    test_date1.day=15;
    test_date1.hour=0;
    test_date1.min=0;
	smonth_info[1]=SolortoSo24(test_date1);  //양력15일날의 절기

    //부활절 계산
	easter_day=0;
	easter_month=0;
	if (year>0)
	{
		test_date1=GetEasterDate(year);

		easter_day=test_date1.day;
		easter_month=test_date1.month;
	}

	int lday=lmonth_info[lmv].moon_next_new.date.day;
	int ingi_day=smonth_info[0].outgi.date.day;

	int dd;
	for(dd=0;dd<month_lastday;dd++)
	{
		int day=dd+1;

		if (day==1)
		{

			day_value[dd][TYPE_Solor_Year]=year; //lunar_info
			day_value[dd][TYPE_Solor_Month]=month; //lunar_info

			day_value[dd][TYPE_Lunar_Year]=lunar_date.lyear; //lunar_info
			day_value[dd][TYPE_Lunar_Month]=lunar_date.lmonth; //lunar_info
			day_value[dd][TYPE_Lunar_Day]=lunar_date.lday; //so24term_month
			if (lunar_date.largemonth) day_value[dd][TYPE_Lunar_largemonth]=1;
			else day_value[dd][TYPE_Lunar_largemonth]=0;
			if (lunar_date.yun_leaf) day_value[dd][TYPE_Lunar_yun_leaf]=1;
			else day_value[dd][TYPE_Lunar_yun_leaf]=0;

			so24_8letter so24_8letter;
			so24_8letter=sydtoso24yd(year,month,1,1,0);

			day_value[dd][TYPE_S60_Year]=so24_8letter.so24year;
			day_value[dd][TYPE_S60_Month]=so24_8letter.so24month;
			day_value[dd][TYPE_S60_Day]=so24_8letter.so24day;

			day_value[dd][TYPE_S_Month_Value]=0;
			day_value[dd][TYPE_L_Month_Value]=lmv;

			day_value[dd][TYPE_Weekday]=getweekday(year,month,1);

			day_value[dd][TYPE_28su_day]=get28sday(year,month,1) ;

			day_value[dd][TYPE_Julian_Date]=getjulianday(year,month,1);


			lday=lmonth_info[lmv].moon_next_new.date.day;
			ingi_day=smonth_info[0].outgi.date.day;
		}
		else
		{
			day_value[dd][TYPE_Weekday]=day_value[dd-1][TYPE_Weekday]+1;
			if (day_value[dd][TYPE_Weekday]==7) day_value[dd][TYPE_Weekday]=0;

			day_value[dd][TYPE_28su_day]=day_value[dd-1][TYPE_28su_day]+1;
			if (day_value[dd][TYPE_28su_day]==28) day_value[dd][TYPE_28su_day]=0;

			day_value[dd][TYPE_Julian_Date]=day_value[dd-1][TYPE_Julian_Date]+1;

			if (day==lday)
			{

				lunar_date=solortolunar(year,month,day);
				lmv=lmv+1;

				lmonth_info[lmv]=lunar_date.moon;


				day_value[dd][TYPE_Lunar_Year]=lunar_date.lyear;
				day_value[dd][TYPE_Lunar_Month]=lunar_date.lmonth; //lunar_info
				day_value[dd][TYPE_Lunar_Day]=lunar_date.lday; //so24term_month

				if (lunar_date.largemonth) day_value[dd][TYPE_Lunar_largemonth]=1;
				else day_value[dd][TYPE_Lunar_largemonth]=0;
				if (lunar_date.yun_leaf) day_value[dd][TYPE_Lunar_yun_leaf]=1;
				else day_value[dd][TYPE_Lunar_yun_leaf]=0;

				day_value[dd][TYPE_L_Month_Value]=lmv;
				lday=lmonth_info[lmv].moon_next_new.date.day;

			}
			else
			{
				day_value[dd][TYPE_Lunar_Year]=day_value[dd-1][TYPE_Lunar_Year];
				day_value[dd][TYPE_Lunar_Month]=day_value[dd-1][TYPE_Lunar_Month];
				day_value[dd][TYPE_Lunar_Day]=day_value[dd-1][TYPE_Lunar_Day]+1;

				day_value[dd][TYPE_Lunar_largemonth]=day_value[dd-1][TYPE_Lunar_largemonth];
				day_value[dd][TYPE_Lunar_yun_leaf]=day_value[dd-1][TYPE_Lunar_yun_leaf];


				day_value[dd][TYPE_L_Month_Value]=day_value[dd-1][TYPE_L_Month_Value];
			}

			if (day==ingi_day)
			{

				day_value[dd][TYPE_S_Month_Value]=1;

				if (smonth_info[1].ingi.name==0)
				{
					day_value[dd][TYPE_S60_Year]=day_value[dd-1][TYPE_S60_Year]+1;
					if (day_value[dd][TYPE_S60_Year]==60) day_value[dd][TYPE_S60_Year]=0;
				}
				else
				{
					day_value[dd][TYPE_S60_Year]=day_value[dd-1][TYPE_S60_Year];
				}

				day_value[dd][TYPE_S60_Month]=day_value[dd-1][TYPE_S60_Month]+1;
				if (day_value[dd][TYPE_S60_Month]==60) day_value[dd][TYPE_S60_Month]=0;

				day_value[dd][TYPE_S60_Day]=day_value[dd-1][TYPE_S60_Day]+1;
				if (day_value[dd][TYPE_S60_Day]==60) day_value[dd][TYPE_S60_Day]=0;

			}
			else
			{
				day_value[dd][TYPE_S60_Year]=day_value[dd-1][TYPE_S60_Year];
				if (day_value[dd][TYPE_S60_Year]==60) day_value[dd][TYPE_S60_Year]=0;

				day_value[dd][TYPE_S60_Month]=day_value[dd-1][TYPE_S60_Month];
				if (day_value[dd][TYPE_S60_Month]==60) day_value[dd][TYPE_S60_Month]=0;

				day_value[dd][TYPE_S60_Day]=day_value[dd-1][TYPE_S60_Day]+1;
				if (day_value[dd][TYPE_S60_Day]==60) day_value[dd][TYPE_S60_Day]=0;

				day_value[dd][TYPE_S_Month_Value]=day_value[dd-1][TYPE_S_Month_Value];
			}


		}
	}

	check_planet_event_month(year,month,timez_off);

	so24_8letter mid_gi_8=sydtoso24yd(smonth_info[1].mingi.date.year,smonth_info[1].mingi.date.month,smonth_info[1].mingi.date.day,smonth_info[1].mingi.date.hour,smonth_info[1].mingi.date.min);

	bool date_set=true;

	int cell;
	int line;
	printf("year=%d month=%d day=%d\n", year, month, day);
	printf("year=%s month=%s ",ganji[mid_gi_8.so24year],ganji[mid_gi_8.so24month]);
	for(line=1;line<7;line++)
	{
		if ((line==6)&&(date_set==false)) break;
		for (cell=0;cell<7;cell++)
		{
			if (date_set)
			{
				//day++;
			
				int lunar_hol=-1;

				if ((day_value[day-1][TYPE_Lunar_yun_leaf]==0)
					&&(day_value[day-1][TYPE_Lunar_Month]==1)
					&&(day_value[day-1][TYPE_Lunar_Day]==1)
				   )
				{
					lunar_hol=0;
				}

				if ((day_value[day-1][TYPE_Lunar_yun_leaf]==0)
						&&(day_value[day-1][TYPE_Lunar_Month]==4)
						&&(day_value[day-1][TYPE_Lunar_Day]==8)
					   )
					{
						if (year>-544)
							lunar_hol=1;
					}

				if ((day_value[day-1][TYPE_Lunar_yun_leaf]==0)
						&&(day_value[day-1][TYPE_Lunar_Month]==8)
						&&(day_value[day-1][TYPE_Lunar_Day]==15)
					   )
					{
						lunar_hol=2;
					}

				if ((day==easter_day)&&(month==easter_month))
				{
					if (year>35)
						lunar_hol=3;
				}
				//printf("%s\n", ganji[day_value[day-1][TYPE_S60_Day]] );

				double jd=getjuliandate_point_pre(year,month,day,21,0);

				if (jd<2299161)
				{
					date_cal jddate=getjuliandate_from_julianday(jd);
					printf("jddate.month=%d jddate.day=%d\n");
				}
				//if (day==month_lastday) date_set=false;
			}
		}
	}
	printf("day=%s\n", ganji[day_value[day-1][TYPE_S60_Day]] );
}

void print_month_info()
{
	printf("this month first=%s\n",get_string_time_local(smonth_info[1].ingi.date,timez_off));
	printf("this month middle=%s\n",get_string_time_local(smonth_info[1].mingi.date,timez_off));
}

int main()
{
	//default
	year=2016;
	month=5;
	timez_off=-540;

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

	print_body_first();
	print_month_table();
	print_month_info();
	return(0);

}
#ifndef MAIN_H
#define MAIN_H

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

int year,month,day,timez_off,lang,hour,minute,gender;
int day_value[31][26];
so24term_month smonth_info[2],umonth_info[2];
moon_info lmonth_info[3];

date_cal cur_time, cur_time_tz;
int cur_time_sec;
char saju[4][5];
int month_flag; // 이번달 절입을 지나지 않았으면 1
char gf_gan[10][3];
char gf_ji[10][3];
char six_chin[8][3];
char gf_six_gan[10][3];
char gf_six_ji[10][3];

int type_sign; //양(1) 음(0)
char type_gs; //관성 mv(0) mi(1) mo(2) mn(3) me(4) ml(5) 
int type_hc; //합(1) 충(0)
int type_yn; //양(1) 음(0)
int type_result; //2*6*2*2 (1~42)


void check_planet_event_month(int wbyear, int wbmonth, int time_offset_chkevent);
void print_input_form();
void print_body_first();
void print_month_table();
void print_time_table();
void print_twelve_star();
int six_sin_x(char id[]);
int six_sin_y(char id[]);
void print_six_sin();
void print_great_fortune(int direction);
int calculate_day(int y, int m, int d);
void calculate_great_foutune();
void great_six_chin();
void cal_type_sign();
void cal_type_gs();
int is_cg_hc(char *id1, char *id2);
int is_jj_hch(char *id1, char *id2);
void cal_type_hc();
void cal_type_yn();
int cal_type_result();

#endif
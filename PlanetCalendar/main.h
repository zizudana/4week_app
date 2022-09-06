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

int year,month,day,timez_off,lang,hour,minute,gender,flag,time_know, time_know_w, time_know_m;
int day_value[31][26];
so24term_month smonth_info[2],umonth_info[2];
moon_info lmonth_info[3];

date_cal cur_time, cur_time_tz;
int cur_time_sec;
char saju[4][5];
char saju2[4][5];
int month_flag; // 이번달 절입을 지나지 않았으면 1
char gf_gan[10][3];
char gf_ji[10][3];
char six_chin[8][3];
char gf_six_gan[10][3];
char gf_six_ji[10][3];

int type_sign; //양(1) 음(0)
int type_gs; //관성 mv(0) mi(1) mo(2) mn(3) me(4) ml(5) 
int type_hc; //합(1) 충(0)
int type_yn; //양(1) 음(0)
char* type_result1;
char* type_result2; //2*6*2*2 (1~42)

int satis_jung; // HA(0) AH(1) 2N(2) 2P(3)
int satis_dowha; // MU(0) WM(1) MW(2) DN(3)
int satis_guin; // GMU(0) GWM(1) GMW(2) GDN(3)
int satis_hc1; // PF(0) PW(1) NR(2)
int satis_hc2; // HM(0) CM(1) HC(2)
int satis_gh; //NBP(0) NCP(1) NGP(2) NNP(3)
int satis_result;

void check_planet_event_month(int wbyear, int wbmonth, int time_offset_chkevent);
void print_input_form(int _gender, int _year, int _month, int _day, int _hours, int _minutes);
void print_body_first(int _gender, int _year, int _month, int _day, int _hours, int _minutes);
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
int cal_type_sign(int s);
void cal_type_gs_m();
void cal_type_gs_w();
int is_cg_hc(char *id1, char *id2);
int is_jj_hc(char *id1, char *id2);
void cal_type_hc();
void cal_type_yn();
const char* cal_type_result();
void cal_satis_jung();
int is_dowha(char *w1, char *i1, char *w2, char *i2 );
int is_guin(char *c, char *z1, char *z2);
void cal_satis_dowha();
void cal_satis_guin();
void cal_satis_hc1();
void cal_satis_hc2();
void cal_satis_gh();
int cal_satis_result();
int _4week(int wgender, int wyear, int wmonth, int wday, int whours, int wminutes, int mgender, int myear, int mmonth, int mday, int mhours, int mminutes);
#endif
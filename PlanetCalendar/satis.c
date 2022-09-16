#include "4week.h"

void cal_satis_jung()
{
  int p1, p2;
  p1 = cal_type_sign(0);
  p2 = cal_type_sign(1);

  printf("-----------------------------\n");
  if (p1 == 0 && p2 == 1)
  {
    satis_jung = 0;
    printf("1. HA\n");
  }
  else if (p1 == 1 && p2 == 0)
  {
    satis_jung = 1;
    printf("1. AH\n");
  }
  else if (p1 == 0 && p2 == 0)
  {
    satis_jung = 2;
    printf("1. 2N\n");
  }
  else if (p1 == 1 && p2 == 1)
  {
    satis_jung = 3;
    printf("1. 2P\n");
  }
}

int is_dowha(char *w1, char *i1, char *w2, char *i2 )
{
  if (!strcmp(w2, "yu") || !strcmp(i2, "yu"))
  {
    if (!strcmp(w1, "si") || !strcmp(w1, "ja") || !strcmp(w1, "ji") || !strcmp(i1, "si") || !strcmp(i1, "ja") || !strcmp(i1, "ji"))
      return (1);
  }
  else if (!strcmp(w2, "my") || !strcmp(i2, "my"))
  {
    if (!strcmp(w1, "in") || !strcmp(w1, "oh") || !strcmp(w1, "su") || !strcmp(i1, "in") || !strcmp(i1, "oh") || !strcmp(i1, "su"))
      return (1);
  }
  else if (!strcmp(w2, "oh") || !strcmp(i2, "oh"))
  {
    if (!strcmp(w1, "sa") || !strcmp(w1, "yu") || !strcmp(w1, "ch") || !strcmp(w1, "sa") || !strcmp(w1, "yu") || !strcmp(w1, "ch"))
      return (1);
  }
  else if (!strcmp(w2, "ja") || !strcmp(i2, "ja"))
  {
    if (!strcmp(w1, "ha") || !strcmp(w1, "my") || !strcmp(w1, "mi") || !strcmp(i1, "ha") || !strcmp(i1, "my") || !strcmp(i1, "mi"))
      return (1);
  }
  return(0);
}

void cal_satis_dowha()
{
  char w1[3]; // 월지지(여)
  char i1[3]; // 일지지(여)
  char w2[3]; // 월지지(남)
  char i2[3]; // 일지지(남)
  int wm; //여->남
  int mw; //남->여

  strncpy(w1, saju1[1]+2, 2);
  w1[2] = '\0';
  strncpy(i1, saju1[2]+2, 2);
  i1[2] = '\0';
  strncpy(w2, saju2[1]+2, 2);
  w2[2] = '\0';
  strncpy(i2, saju2[2]+2, 2);
  i2[2] = '\0';
  wm = is_dowha(w1, i1, w2, i2);
  mw = is_dowha(w2, i2, w1, i1);
  if (wm == 1 && mw == 1)
  {
    satis_dowha = 0;
    printf("2. MU\n");
  }
  else if (wm == 1)
  {
    satis_dowha = 1;
    printf("2. WM\n");
  }
  else if (mw == 1)
  {
    satis_dowha = 2;
    printf("2. MW\n");
  }
  else
  {
    satis_dowha = 3;
    printf("2. DN\n");
  }
}

int is_guin(char *c, char *z1, char *z2)
{
  if (!strcmp(c, "ga") || !strcmp(c, "mu") || !strcmp(c, "gy"))
  {
    if (!strcmp(z1, "ch") || !strcmp(z1, "mi") || !strcmp(z2, "ch") || !strcmp(z2, "mi"))
      return(1);
  }
  else if (!strcmp(c, "eu") || !strcmp(c, "gi"))
  {
    if (!strcmp(z1, "ja") || !strcmp(z1, "si") || !strcmp(z2, "ja") || !strcmp(z2, "si"))
      return(1);
  }
  else if (!strcmp(c, "by") || !strcmp(c, "je"))
  {
    if (!strcmp(z1, "ha") || !strcmp(z1, "yu") || !strcmp(z2, "ha") || !strcmp(z2, "yu"))
      return(1);
  }
  else if (!strcmp(c, "sn"))
  {
    if (!strcmp(z1, "oh") || !strcmp(z1, "in") || !strcmp(z2, "oh") || !strcmp(z2, "in"))
      return(1);
  }
  else if (!strcmp(c, "im") || !strcmp(c, "ge"))
  {
    if (!strcmp(z1, "sa") || !strcmp(z1, "my") || !strcmp(z2, "sa") || !strcmp(z2, "my"))
      return(1);
  }
  return (0);
}

void cal_satis_guin()
{
  char c[3]; // 일천간
  char z1[3]; // 월지지
  char z2[3]; // 일지지
  int wm; //여->남
  int mw; //남->여

  strncpy(c, saju1[2], 2);
  c[2] = '\0';
  strncpy(z1, saju2[1]+2, 2);
  z1[2] = '\0';
  strncpy(z2, saju2[2]+2, 2);
  z2[2] = '\0';
  mw = is_guin(c, z1, z2);

  strncpy(c, saju2[2], 2);
  c[2] = '\0';
  strncpy(z1, saju1[1]+2, 2);
  z1[2] = '\0';
  strncpy(z2, saju1[2]+2, 2);
  z2[2] = '\0';
  wm = is_guin(c, z1, z2);

  if (wm == 1 && mw == 1)
  {
    satis_guin = 0;
    printf("3. GMU\n");
  }
  else if (wm == 1)
  {
    satis_guin = 1;
    printf("3. GWM\n");
  }
  else if (mw == 1)
  {
    satis_guin = 2;
    printf("3. GMW\n");
  }
  else
  {
    satis_guin = 3;
    printf("3. GDN\n");
  }
}

void cal_satis_hc1()
{
  char m[3];
  char w[3];
  int hc;

  strncpy(w, saju1[2], 2);
  w[2] = '\0';
  strncpy(m, saju2[2], 2);
  m[2] = '\0';
  hc = is_cg_hc(w, m);
  if (hc == 2)
  {
    satis_hc1 = 0;
    printf("4. PF\n");
  }
  else if (hc == 1)
  {
    satis_hc1 = 1;
    printf("4. PW\n");
  }
  else
  {
    satis_hc1 = 2;
    printf("4. NR\n");
  }
}

void cal_satis_hc2()
{
  int i;
  int j;
  char id1[3]; // 여
  char id2[3]; // 남
  int h; // 합
  int ch; // 충+형
  int cnt;
  int idx_w = 4;
  int idx_m = 4;

  if (!time_know_w)
    idx_w = 3;
  if (!time_know_m)
    idx_m = 3;
  h = 0;
  ch = 0;
  for (i=0; i<idx_w; i++)
  {
    strncpy(id1, saju1[i], 2);
    id1[2] = '\0';
    for (j=0; j<idx_m; j++)
    {
      strncpy(id2, saju2[j], 2);
      id2[2] = '\0';
      cnt = is_cg_hc(id1, id2);
      if (cnt == 2)
        h++;
      else if (cnt == 1)
        ch++;
    }
  }

  for (i=0; i<idx_w; i++)
  {
    strncpy(id1, saju1[i]+2, 2);
    id1[2] = '\0';
    for (j=0; j<idx_m; j++)
    {
      strncpy(id2, saju2[j]+2, 2);
      id2[2] = '\0';
      //printf("id1 = %s id2 = %s\n", id1, id2);
      cnt = is_jj_hc(id1, id2);
      if (cnt == 2)
        h++;
      else if (cnt == 1)
        ch++;
    }
  }
  
  if (h >= ch)
  {
    satis_hc2 = 0;
    printf("5. HM");
  }
  else if (h < ch)
  {
    satis_hc2 = 1;
    printf("5. CM");
  }
  else
  {
    satis_hc2 = 2;
    printf("5. HC");
  }
}

void cal_satis_gh()
{
  char m1[3]; // 월지(여)
  char d1[3]; // 일지(여)
  char m2[3]; // 월지(남)
  char d2[3]; // 일지(남)
  int cp = 0;
  int gp = 0;
  satis_gh = 0;

  strncpy(m1, saju1[1]+2, 2);
  m1[2] = '\0';
  strncpy(d1, saju1[2]+2, 2);
  d1[2] = '\0';
  strncpy(m2, saju2[1]+2, 2);
  m2[2] = '\0';
  strncpy(d2, saju2[2]+2, 2);
  d2[2] = '\0';

  if (!strcmp(m1, "ja") || !strcmp(d1, "ja"))
  {
    if (!strcmp(m2, "my") || !strcmp(d2, "my"))
      cp = 1;
  }
  if (!strcmp(m2, "ja") || !strcmp(d2, "ja"))
  {
    if (!strcmp(m1, "my") || !strcmp(d1, "my"))
      cp = 1;
  }
  if (!strcmp(m1, "su") || !strcmp(d1, "su"))
  {
    if (!strcmp(m2, "ch") || !strcmp(d2, "ch") || !strcmp(m2, "mi") || !strcmp(d2, "mi"))
      gp = 1;
  }
  if (!strcmp(m2, "su") || !strcmp(d2, "su"))
  {
    if (!strcmp(m1, "ch") || !strcmp(d1, "ch") || !strcmp(m1, "mi") || !strcmp(d1, "mi"))
      gp = 1;
  }
  
  if (cp && gp)
  {
    satis_gh = 0;
    printf("\n6. NBP");
  }
  else if (cp)
  {
    satis_gh = 1;
    printf("\n6. NCP");
  }
  else if (gp)
  {
    satis_gh = 2;
    printf("\n6. NGP");
  }
  else
  {
    satis_gh = 3;
    printf("\n6. NNP");
  }
}

int cal_satis_result()
{
  switch(satis_jung)
  {
    case 0: //HA
      switch(satis_dowha)
      {
        case 0: //MU
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (1); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (2); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (3); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (4); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (5); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (6); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (7); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (8); // NR CM
          else 
            return (9); // NR HC

        case 1: //WM
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (10); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (11); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (12); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (13); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (14); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (15); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (16); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (17); // NR CM
          else 
            return (18); // NR HC

        case 2: //MW
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (19); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (20); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (21); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (22); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (23); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (24); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (25); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (26); // NR CM
          else 
            return (27); // NR HC
        
        case 3: //DN
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (28); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (29); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (30); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (31); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (32); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (33); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (34); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (35); // NR CM
          else 
            return (36); // NR HC
      }

    case 1: //AH
      switch(satis_dowha)
      {
        case 0: //MU
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (37); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (38); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (39); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (40); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (41); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (42); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (43); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (44); // NR CM
          else 
            return (45); // NR HC

        case 1: //WM
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (46); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (47); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (48); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (49); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (50); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (51); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (52); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (53); // NR CM
          else 
            return (54); // NR HC

        case 2: //MW
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (55); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (56); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (57); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (58); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (59); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (60); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (61); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (62); // NR CM
          else 
            return (63); // NR HC
        
        case 3: //DN
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (64); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (65); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (66); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (67); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (68); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (69); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (70); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (71); // NR CM
          else 
            return (72); // NR HC
      }
  case 2: //2N
      switch(satis_dowha)
      {
        case 0: //MU
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (73); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (74); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (75); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (76); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (77); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (78); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (79); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (80); // NR CM
          else 
            return (81); // NR HC

        case 1: //WM
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (82); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (83); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (84); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (85); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (86); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (87); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (88); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (89); // NR CM
          else 
            return (90); // NR HC

        case 2: //MW
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (91); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (92); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (93); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (94); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (95); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (96); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (97); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (98); // NR CM
          else 
            return (99); // NR HC
        
        case 3: //DN
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (100); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (101); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (102); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (103); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (104); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (105); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (106); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (107); // NR CM
          else 
            return (108); // NR HC
      }
  case 3: //2P
      switch(satis_dowha)
      {
        case 0: //MU
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (109); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (110); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (111); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (112); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (113); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (114); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (115); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (116); // NR CM
          else 
            return (117); // NR HC

        case 1: //WM
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (118); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (119); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (120); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (121); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (122); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (123); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (124); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (125); // NR CM
          else 
            return (126); // NR HC

        case 2: //MW
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (127); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (128); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (129); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (130); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (131); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (132); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (133); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (134); // NR CM
          else 
            return (135); // NR HC
        
        case 3: //DN
          if (satis_hc1 == 0 && satis_hc2 == 0)
            return (136); // PF HM
          else if (satis_hc1 == 0 && satis_hc2 == 1)
            return (137); // PF CM
          else if (satis_hc1 == 0 && satis_hc2 == 2)
            return (138); // PF HC
          else if (satis_hc1 == 1 && satis_hc2 == 0)
            return (139); // PW HM
          else if (satis_hc1 == 1 && satis_hc2 == 1)
            return (140); // PW CM
          else if (satis_hc1 == 1 && satis_hc2 == 2)
            return (141); // PW HC
          else if (satis_hc1 == 2 && satis_hc2 == 0)
            return (142); // NR HM
          else if (satis_hc1 == 2 && satis_hc2 == 1)
            return (143); // NR CM
          else 
            return (144); // NR HC
      }
  }
}